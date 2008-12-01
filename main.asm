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
%include "syscalls.h"

;; Number of command line arguments
%define ARGC              4
;; Maximum size of a .COM file
%define COMFILEMAXSIZE    0xFFFF

; In:         buffer byte
; Destroys:   ax, bx
%macro GetOpcodePosition 1
  mov eax, %1
  mov ebx, [opcodes]
  mov ecx, Opcode_size
  mul ecx
  add ebx, eax
%endmacro

%macro LoadOpcodeData 1
  StoreOpcodeData 32, [ebx + Opcode.mnemonic], [mnemonic]
  StoreOpcodeData 32, [ebx + Opcode.arg1_type], [arg1_type]
  StoreOpcodeData 8,  [ebx + Opcode.arg1_reg16bits], [arg1_reg16bits]
  StoreOpcodeData 32, [ebx + Opcode.arg2_type], [arg2_type]
  StoreOpcodeData 8,  [ebx + Opcode.arg2_reg16bits], [arg2_reg16bits]

  ;; TODO: there are subtle differences between these two
  ;ProcessArgument arg1
  ;ProcessArgument arg2
%endmacro

%macro ProcessArgument 1
  cmp dword [type_%1], ARGTYPE_REGMEM
  jae %%addr_regmem ;; both REGMEM and REGISTER
  cmp dword [type_%1], ARGTYPE_NONE
  je  %%addr_end
  cmp dword [type_%1], ARGTYPE_CONST1
  je  %%addr_const1
  cmp dword [type_%1], ARGTYPE_CONST3
  je  %%addr_const3
  cmp dword [type_%1], ARGTYPE_IMMED
  je  %%addr_immed
  cmp dword [type_%1], ARGTYPE_MEMORY
  je  %%addr_immed ;; works just like immed in this context

  %%addr_const1:
    mov [%1_displacement], word 1
    jmp %%addr_end

  %%addr_const3:
    mov [%1_displacement], word 3
    jmp %%addr_end

  ;; ARGTYPE_IMMED and ARGTYPE_MEMORY
  %%addr_immed:
    test [reg16bits], byte 1
    jne %%addr_immed16
    ;; 8-bit version
    inc esi
    mov dl, [comfile + esi]
    mov [%1_displacement], dl
    inc esi
    jmp %%addr_end
    ;; 16-bit version
  %%addr_immed16:
    inc esi
    mov dx, [comfile + esi]
    mov [%1_displacement], dx
    inc esi
    inc esi
    jmp %%addr_end

  ;; ARGTYPE_REGMEM and ARGTYPE_REGISTER
  %%addr_regmem:
    sys_write [logfile_fd], usage_msg, 4
    jmp %%addr_end
  %%addr_end:
%endmacro

;; In:        register size, src, dest
;; Destroys:  edx
%macro StoreOpcodeData 3
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
  arg1_type                 resd    1
  arg1_reg16bits            resb    1
  arg1_basereg              resd    1
  arg1_indexreg             resd    1
  arg1_displacement         resw    1
  arg2_type                 resd    1
  arg2_reg16bits            resb    1
  arg2_basereg              resd    1
  arg2_indexreg             resd    1
  arg2_displacement         resw    1


section .data
  ;; Error messages
  open_input_file_msg       db      "Erro ao abrir arquivo executavel", 0x0A, 0
  open_input_file_msg_len   equ     $-open_input_file_msg
  open_output_file_msg      db      "Erro ao abrir arquivo de saida", 0x0A, 0
  open_output_file_msg_len  equ     $-open_output_file_msg
  usage_msg                 db      "Uso: ./decompify executavel.com output.asm", 0x0A, 0
  usage_msg_len             equ     $-usage_msg


section .text
  extern disasm_write_header, get_file_size
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
  sys_read [comfile_fd], comfile, [comfile_size]
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
    jae .end_main_loop

    ;; Get the corresponding opcode position in the table
    GetOpcodePosition [comfile + esi] ; ebx = opcodes[[comfile+esi]]
    LoadOpcodeData ebx

    inc esi
    jmp .main_loop
  .end_main_loop:

  ;; Close the files and exit
  sys_close [asmfile_fd]
  sys_close [logfile_fd]
  sys_exit EX_OK

.exit_open_input_file:
  sys_write STDOUT, open_input_file_msg, open_input_file_msg_len
  sys_exit EX_DATAERR

.exit_open_output_file:
  sys_write STDOUT, open_output_file_msg, open_output_file_msg_len
  sys_exit EX_DATAERR

.exit_usage:
  sys_write STDOUT, usage_msg, usage_msg_len
  sys_exit  EX_USAGE

; vim:syntax=nasm:
