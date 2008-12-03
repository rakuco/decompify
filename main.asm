;;
;; MC404ABCD - 2008s2
;; Projeto 2
;;     decompify - COM files disassembler for Linux.
;;
;; 071294 - Jorge Augusto Hongo
;; 072201 - Raphael Kubo da Costa
;;
;;     Copyright (C) 2008  Jorge Augusto Hongo
;;     Copyright (C) 2008  Raphael Kubo da Costa
;;
;;     This program is free software: you can redistribute it and/or modify
;;     it under the terms of the GNU General Public License as published by
;;     the Free Software Foundation, either version 3 of the License, or
;;     (at your option) any later version.
;;
;;     This program is distributed in the hope that it will be useful,
;;     but WITHOUT ANY WARRANTY; without even the implied warranty of
;;     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;     GNU General Public License for more details.
;;
;;     You should have received a copy of the GNU General Public License
;;     along with this program.  If not, see <http://www.gnu.org/licenses/>.
;;

%include "instr.h"
%include "opcodes.h"
%include "string.h"
%include "syscalls.h"
%include "util.h"

;; Number of command line arguments
%define ARGC              4
;; Maximum size of a .COM file
%define COMFILEMAXSIZE    0xFFFF

;; GetArrayPosition(void *buffer, int pos, size_t item_size)
;; Destroys:    ebx
%macro GetArrayPosition 3
  push eax
  push ecx
  xor  ecx, ecx
  mov  cl,  %2
  mov  ebx, %1
  mov  eax, %3
  mul  ecx
  add  ebx, eax
  pop  ecx
  pop  eax
%endmacro

%macro GetRMReg 1
  shr %1, 3
  and %1, 0x7
%endmacro

%macro LoadOpcodeData 1
  ;; XXX: debug code; remove for production
  ;mov ebx, opcodes
  ;mov edi, [ebx+198+Opcode.mnemonic]
  ;sys_write [logfile_fd], edi, 4
  ;mov edi, [ebx+Opcode.mnemonic]
  ;sys_write [logfile_fd], edi, 4

  StoreData 32, [ebx + Opcode.mnemonic], [mnemonic]
  StoreData 32, [ebx + Opcode.group_id], [group_id]
  StoreData 32, [ebx + Opcode.segment_id], [segment_id]
  StoreData 32, [ebx + Opcode.arg1_type], [arg1_type]
  StoreData 8,  [ebx + Opcode.arg1_reg16bits], [arg1_reg16bits]
  StoreData 32, [ebx + Opcode.arg2_type], [arg2_type]
  StoreData 8,  [ebx + Opcode.arg2_reg16bits], [arg2_reg16bits]

  ;; If it's a group, move the mnemonic to [mnemonic]
  cmp [group_id], dword 0
  je  %%no_group
  mov al, [comfile+esi]
  GetRMReg al
  GetArrayPosition [group_id], al, 4
  StoreData 32, [ebx], [mnemonic]

  ;; TODO: there are subtle differences between these two
  %%no_group:
    ProcessArgument arg1
    ProcessArgument arg2
%endmacro

%macro PrintInstruction 0
  ;; Mnemonic
  exec write_string, [asmfile_fd], [mnemonic]

  ;; Argument 1
  cmp dword [arg1_type], ARGTYPE_NONE
  je %%end
  exec write_string, [asmfile_fd], space

  ;; Argument 2
  cmp dword [arg2_type], ARGTYPE_NONE
  je %%end
  exec write_string, [asmfile_fd], comma

  ;; End
  %%end:
    exec write_string, [asmfile_fd], nl
%endmacro

%macro ProcessArgument 1
  ; Constant arguments
  mov edx, [%1_type]
  cmp edx, ARGTYPE_NONE
  je  %%addr_end
  cmp edx, ARGTYPE_REGDS  ; Last constant argument in the array
  jbe %%addr_const
  cmp edx, ARGTYPE_RM_BOTH ; First of its kind in the array
  jae %%addr_regmem
  jmp %%addr_immed  ; FIXME: there will be other types, this comparison will grow

  %%addr_const:
    ;; %1_displacement = ARRAY_CONSTARGS[4*argN_type]
    xor edx, edx
    mov dl, [%1_type]
    StoreData 32, [4*edx+ARRAY_CONSTARGS], [%1_displacement]

    jmp %%addr_end

  %%addr_regmem:
    jmp %%addr_end

  %%addr_immed:
    jmp %%addr_end

  %%addr_end:
%endmacro

;; In:        register size, src, dest
;; Destroys:  edx
%macro StoreData 3
  %push TempContext

  %if %1 == 8
    %define %$reg dl
  %elif %1 == 32
    %define %$reg edx
  %else
    %error "First argument must be 8 or 32"
  %endif

  mov %$reg, %2
  mov %3, %$reg

  %pop
%endmacro


section .bss
  ;; Files (input and output)
  asmfile_fd                resw    2
  asmfile_name              resb    255
  comfile                   resb    COMFILEMAXSIZE
  comfile_fd                resw    2
  comfile_name              resb    255
  comfile_size              resw    1
  logfile_name resb 255
  logfile_fd resw 2

  ;; Opcode and its operands
  mnemonic                  resd    1
  group_id                  resd    1
  segment_id                resd    1
  arg1_type                 resd    1
  arg1_reg16bits            resb    1
  arg1_basereg              resd    1
  arg1_indexreg             resd    1
  arg1_displacement         resd    1
  arg2_type                 resd    1
  arg2_reg16bits            resb    1
  arg2_basereg              resd    1
  arg2_indexreg             resd    1
  arg2_displacement         resd    1


section .data
  ;; Error messages
  open_input_file_msg       db    "Erro ao abrir arquivo executavel", 0x0A, 0
  open_output_file_msg      db    "Erro ao abrir arquivo de saida", 0x0A, 0
  usage_msg                 db    "Uso: ./decompify executavel.com output.asm", 0x0A, 0


section .text
  extern disasm_write_header, get_file_size, strlen, write_string
  global _start

_start:
  ;; Check arguments and exit if the command line is incorrect
  pop eax
  cmp eax, ARGC
  jne near .exit_usage

  ;; Skip the first argument (executable name) and get the file names
  pop eax
  pop dword [comfile_name]
  pop dword [asmfile_name]
  pop dword [logfile_name]

  sys_open [logfile_name], O_WRONLY|O_TRUNC|O_CREAT
  cmp eax, -1
  jle near .exit_open_input_file
  mov [logfile_fd], eax

  ;; Open the .COM file, exit on error
  sys_open [comfile_name]
  cmp eax, -1
  jle near .exit_open_input_file
  mov [comfile_fd], eax

  ;; Read its whole content and close the file
  push word [comfile_fd]
  call get_file_size
  add esp, 4
  mov [comfile_size], eax
  sys_lseek [comfile_fd], 0, SEEK_SET
  sys_read  [comfile_fd], comfile, [comfile_size]
  sys_close [comfile_fd]

  ;; Open the output .ASM file, exit on error
  sys_open [asmfile_name], O_WRONLY|O_TRUNC|O_CREAT
  cmp eax, -1
  jle near .exit_open_output_file
  mov [asmfile_fd], eax

  ;; Write the code header
  push dword [asmfile_fd]
  call disasm_write_header
  add esp, 4

  ;; Main loop
  xor esi, esi
  .main_loop:
    cmp esi, [comfile_size]
    jae near .end_main_loop

    ;; Get the corresponding opcode position in the table
    ;; ebx = opcodes[[comfile+esi]]
    GetArrayPosition opcodes, [comfile + esi], Opcode_size

    ;; Increment position counter
    inc esi

    LoadOpcodeData ebx

    PrintInstruction

    jmp .main_loop
  .end_main_loop:

  ;; Close the files and exit
  sys_close [asmfile_fd]
  sys_close [logfile_fd]
  sys_exit EX_OK

.exit_open_input_file:
  print_string(open_input_file_msg)
  sys_exit EX_DATAERR

.exit_open_output_file:
  print_string(open_output_file_msg)
  sys_exit EX_DATAERR

.exit_usage:
  print_string(usage_msg)
  sys_exit  EX_USAGE

; vim:syntax=nasm:
