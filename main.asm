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
%define ARGC              3
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

;; In: al
;; Returns a register from ARRAY_8 or 16BITREGS
%macro GetRegister 1
  test [%1_reg16bits], byte 1
  jz  %%8bitreg
    mov edx, ARRAY_16BITREGS
    jmp %%reg
  %%8bitreg:
    mov edx, ARRAY_8BITREGS
  %%reg:
    GetArrayPosition edx, al, 4
%endmacro

;; r/m-related macros
;; ------------------
%macro GetRMmod 1
  shr %1, 6
  and %1, 0x3
%endmacro

%macro GetRMreg 1
  shr %1, 3
  and %1, 0x7
%endmacro

%macro GetRMrm 1
  and %1, 0x7
%endmacro

;; PrintArguments (argN)
;;   Main function to display an instruction.
%macro PrintArguments 1
  cmp dword [%1_type], ARGTYPE_REGDS
  jbe near %%arg_constant
  cmp dword [%1_type], ARGTYPE_MEMORY
  je  near %%arg_memory
  cmp dword [%1_type], ARGTYPE_IMMED
  je  near %%arg_immed
  cmp dword [%1_type], ARGTYPE_RELATIVE
  je  near %%arg_relative
  cmp dword [%1_type], ARGTYPE_FAR
  je  near %%arg_far
  cmp dword [%1_type], ARGTYPE_SIMMED
  je  near %%arg_simmed
  cmp dword [%1_type], ARGTYPE_RM_BOTH
  jae near %%arg_rm

  %%arg_constant:
    mov edi, [%1_displacement]
    exec write_string, [asmfile_fd], [edi]
    jmp near %%arg_end

  %%arg_memory:
    exec write_string, [asmfile_fd], memstart
    call write_segment
    exec write_string, [asmfile_fd], hexstart
    exec write_hex,    [asmfile_fd], [%1_displacement], 16
    exec write_string, [asmfile_fd], memend
    jmp near %%arg_end

  %%arg_immed:
    exec write_string, [asmfile_fd], hexstart
    test byte [%1_reg16bits], 1
    jz   %%arg_immed8
    exec write_hex,    [asmfile_fd], [%1_displacement], 16
    jmp  %%arg_end
  %%arg_immed8:
    exec write_hex,    [asmfile_fd], [%1_displacement], 8
    jmp near %%arg_end

  %%arg_relative:
    exec write_string, [asmfile_fd], s_dollar
    exec write_string, [asmfile_fd], s_dollar
    exec write_string, [asmfile_fd], plus
    exec write_string, [asmfile_fd], hexstart
    test byte [%1_reg16bits], 1
    jz   %%arg_relative8
    exec write_hex,    [asmfile_fd], [%1_displacement], 16
    jmp  %%arg_end
  %%arg_relative8:
    exec write_hex,    [asmfile_fd], [%1_displacement], 8
    jmp near %%arg_end

  %%arg_far:
    exec write_string, [asmfile_fd], hexstart
    exec write_hex,    [asmfile_fd], [arg2_displacement], 16
    exec write_string, [asmfile_fd], colon
    exec write_string, [asmfile_fd], hexstart
    exec write_hex,    [asmfile_fd], [arg1_displacement], 16
    jmp  near %%arg_end

  %%arg_simmed:
    exec write_string, [asmfile_fd], s_byte
    exec write_string, [asmfile_fd], space
    test byte [%1_displacement], 0x80
    jnz  %%arg_simmed_neg
    exec write_string, [asmfile_fd], plus
    jmp  %%arg_simmed_writenum
  %%arg_simmed_neg:
    exec write_string, [asmfile_fd], minus
  %%arg_simmed_writenum:
    exec write_string, [asmfile_fd], hexstart
    exec write_hex,    [asmfile_fd], [%1_displacement], 8
    jmp  near %%arg_end

  ;; FIXME: this is a behemoth
  %%arg_rm:
    ;; XXX: hack for GRP3 and its annoying operators
    ;;      if we have 'jmp/call far/near', we need to write
    ;;      these words before the operands
    cmp  dword [group_id], ARRAY_GRP_GRP3
    jne  near %%not_grp3
    cmp  dword [arg1_basereg], SARGTYPE_REGDX
    je   %%grp3_write_near
    cmp  dword [arg1_basereg], SARGTYPE_REGSP
    je   %%grp3_write_near
    cmp  dword [arg1_basereg], SARGTYPE_REGBX
    je   %%grp3_write_far
    cmp  dword [arg1_basereg], SARGTYPE_REGBP
    je   %%grp3_write_far
    jmp  %%not_grp3
  %%grp3_write_near:
    exec write_string, [asmfile_fd], s_near
    exec write_string, [asmfile_fd], space
    jmp %%not_grp3
  %%grp3_write_far:
    exec write_string, [asmfile_fd], s_far
    exec write_string, [asmfile_fd], space

  ;; Checks if we only have a basereg
  %%not_grp3:
    cmp  dword [%1_type], ARGTYPE_RM_REGISTER
    je   %%write_register_basereg
    cmp  dword [%1_type], ARGTYPE_RM_SEGMENT
    je   %%write_segment_basereg
    jmp  %%arg_rm_not_rm_register
  %%write_register_basereg:
    exec write_string, [asmfile_fd], [arg1_basereg]
    jmp  near %%arg_end
  %%write_segment_basereg:
    exec write_string, [asmfile_fd], [%1_basereg]
    jmp  near %%arg_end

  %%arg_rm_not_rm_register:
    cmp  dword [arg1_indexreg], SARGTYPE_REGDI
    ja   %%arg_rm_normalflow
    cmp  dword [arg1_indexreg], 0
    je   %%arg_rm_normalflow
    cmp  dword [arg1_displacement], 0
    jne  %%arg_rm_normalflow
    exec write_string, [asmfile_fd], [arg1_indexreg]
    jmp  %%arg_end
  %%arg_rm_normalflow:
    ;; Only write 'word' or 'byte' in the first operand
    %ifidn %1,arg1
      cmp  byte [arg1_reg16bits], 1
      jne  %%write_byte
      exec write_string, [asmfile_fd], s_word
      jmp  %%write_normalflow
      %%write_byte:
      exec write_string, [asmfile_fd], s_byte
      %%write_normalflow:
      exec write_string, [asmfile_fd], space
    %endif
    exec write_string, [asmfile_fd], memstart
    call write_segment
    cmp  dword [arg1_indexreg], 0
    je   %%arg_rm_writedisp
    exec write_string, [asmfile_fd], [arg1_indexreg]
    cmp  dword [arg1_displacement], 0
    je   %%arg_rm_writeend
    exec write_string, [asmfile_fd], plus
  %%arg_rm_writedisp:
    exec write_string, [asmfile_fd], hexstart
    exec write_hex,    [asmfile_fd], [arg1_displacement], 16
  %%arg_rm_writeend:
    exec write_string, [asmfile_fd], memend
    jmp %%arg_end

  %%arg_end:
%endmacro

%macro ProcessArgument 1
  ; Constant arguments
  cmp dword [%1_type], ARGTYPE_NONE
  je  near %%addr_end
  cmp dword [%1_type], ARGTYPE_REGDS   ; Last constant argument in the array
  jbe near %%addr_const
  cmp dword [%1_type], ARGTYPE_RM_BOTH ; First of its kind in the array
  jae near %%addr_regmem
  cmp dword [%1_type], ARGTYPE_MEMORY  ; Last of its kind
  jbe near %%addr_memory
  cmp dword [%1_type], ARGTYPE_RELATIVE
  je  near %%addr_relative
  cmp dword [%1_type], ARGTYPE_FAR ; FAR can only be used as arg1_type, not arg2!
  je  near %%addr_far

  %%addr_const:
    ;; %1_displacement = ARRAY_CONSTARGS[4*argN_type]
    mov edx, [%1_type]
    GetArrayPosition ARRAY_CONSTARGS, [edx], 4
    mov [%1_displacement], ebx

    jmp %%addr_end

  %%addr_regmem:
    ProcessRM %1
    jmp %%addr_end

  %%addr_memory:
    xor edx, edx
    test [%1_reg16bits], byte 1
    jz  %%addr_memory8
    mov dx, [comfile+esi]
    inc esi
    inc esi
    jmp %%addr_memoryset
  %%addr_memory8:
    mov dl, [comfile+esi]
    inc esi
  %%addr_memoryset:
    mov [%1_displacement], edx
    jmp %%addr_end

  %%addr_relative:
    xor edx, edx
    test [%1_reg16bits], byte 1
    jz  %%addr_relative8
    mov ax, [comfile+esi]
    inc esi
    inc esi
    jmp %%addr_relativeset
  %%addr_relative8:
    mov al, [comfile+esi]
    cbw
    mov byte [%1_reg16bits], 1 ;; After the operations, it needs to be a word
    inc esi
  %%addr_relativeset:
    add eax, esi
    mov [%1_displacement], eax
    jmp %%addr_end

  %%addr_far:
    xor eax, eax
    mov ax, [comfile+esi]
    mov [arg1_displacement], eax
    inc esi
    inc esi
    xor eax, eax
    mov ax, [comfile+esi]
    mov [arg2_displacement], eax
    inc esi
    inc esi

  %%addr_end:
%endmacro

%macro ProcessRM 1
;; This should execute only once per instruction;
;; the arguments for arg2 are set in the first run
%ifidn %1, arg1
  mov cl, [comfile+esi]
  mov al, cl

  ;; modREGrm
  GetRMreg al
  GetRegister arg1
  StoreData 32, [ebx], [arg1_basereg]

  ;; If it's a segment register, overwrite [argN_basereg] with the new pointer
  RewriteBaseIfSegment arg1
  RewriteBaseIfSegment arg2

  ;; By default, set displacement and indexreg to zero
  ;; If they're used, they're set to their values later
  StoreData 32, dword 0, [arg1_displacement]
  StoreData 32, dword 0, [arg1_indexreg]

  ;; MODregrm
  mov al, cl
  GetRMmod al
  cmp al, 0
  je  %%mod00
  cmp al, 1
  je  %%mod01
  cmp al, 2
  je  %%mod10
  cmp al, 3
  je  %%mod11
  %%mod00:
    StoreData 32, dword 0, [arg1_displacement]
    mov al, cl
    and al, 7
    cmp al, 6
    jne %%mod_end
    jmp %%mod10
  %%mod01:
    xor eax, eax
    mov al, [comfile+esi+1]
    cbw
    cwde
    StoreData 32, eax, [arg1_displacement]
    inc esi
    jmp %%mod_end
  %%mod10:
    xor eax, eax
    mov ax, [comfile+esi+1]
    StoreData 32, eax, [arg1_displacement]
    inc esi
    inc esi
    jmp %%mod_end
  %%mod11:
    mov al, cl
    GetRMrm al
    GetRegister arg1
    StoreData 32, [ebx], [arg1_indexreg]
    jmp %%end ;; rm is a reg field, skip its parsing
  %%mod_end:

  ;; modregRM
  mov al, cl
  GetRMmod al
  cmp al, 0
  jne %%rm_notmod110
  mov al, cl
  and al, 7
  cmp al, 6
  je  %%end ;; mod==00 && rm==110 has been treated in %%mod00
  %%rm_notmod110:
    mov al, cl
    GetRMrm al
    GetArrayPosition ARRAY_RM_MODES, al, 4
    StoreData 32, [ebx], [arg1_indexreg]

  %%end:
    inc esi
%endif
%endmacro

%macro RewriteBaseIfSegment 1
  cmp dword [%1_type], ARGTYPE_RM_SEGMENT
  jne %%end
  GetArrayPosition ARRAY_SEGMENTS, al, 4
  StoreData 32, [ebx], [%1_basereg]

  %%end:
%endmacro

;; In:        register size, src, dest
;; Destroys:  edx
;; Handy macro when you have something like mov [dest], [src]
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
  comfile_size              resw    2

  ;; Opcode and its operands
  opcode                    resb    1
  mnemonic                  resd    1
  group_id                  resd    1
  segment_id                resd    1
  arg1_type                 resd    1
  arg1_basereg              resd    1
  arg1_indexreg             resd    1
  arg1_reg16bits            resb    1
  arg1_displacement         resd    1
  arg2_type                 resd    1
  arg2_basereg              resd    1
  arg2_indexreg             resd    1
  arg2_reg16bits            resb    1
  arg2_displacement         resd    1


section .data
  ;; Error messages
  open_input_file_msg       db    "Erro ao abrir arquivo executavel", 0x0A, 0
  open_output_file_msg      db    "Erro ao abrir arquivo de saida", 0x0A, 0
  usage_msg                 db    "Uso: ./decompify executavel.com output.asm", 0x0A, 0


section .text
  extern disasm_write_header, get_file_size, strlen, write_hex, write_string
  global _start

load_opcode_data:
  ;; If it's a segment, load the next byte and preserve the segment reference
  cmp dword [ebx + Opcode.segment_id], 0
  je  .not_segment
  StoreData 32, [ebx + Opcode.segment_id], [segment_id]
  GetArrayPosition opcodes, [comfile + esi], Opcode_size
  mov cl, [comfile+esi]
  mov [opcode], cl
  inc esi
  jmp .load_data

  .not_segment:
    StoreData 32, [ebx + Opcode.segment_id], [segment_id]
  .load_data:
    StoreData 32, [ebx + Opcode.mnemonic], [mnemonic]
    StoreData 32, [ebx + Opcode.group_id], [group_id]
    StoreData 32, [ebx + Opcode.arg1_type], [arg1_type]
    StoreData 8,  [ebx + Opcode.arg1_reg16bits], [arg1_reg16bits]
    StoreData 32, [ebx + Opcode.arg2_type], [arg2_type]
    StoreData 8,  [ebx + Opcode.arg2_reg16bits], [arg2_reg16bits]

    ;; If it's a group, move the mnemonic to [mnemonic]
    cmp [group_id], dword 0
    je  .process_arguments
    mov al, [comfile+esi]
    GetRMreg al
    GetArrayPosition [group_id], al, 4 ;; ebx = group_id[4*al]
    StoreData 32, [ebx], [mnemonic]
    cmp dword [mnemonic], 0
    jne .process_arguments
    StoreData 32, ARGTYPE_NONE, [arg1_type] ;; If the mnemonic was not found,
    StoreData 32, ARGTYPE_NONE, [arg2_type] ;; make the arguments None.

  .process_arguments:
    ProcessArgument arg1
    ProcessArgument arg2

    ret

print_instruction:
  cmp dword [arg1_type], ARGTYPE_RM_BOTH
  jae .check_mnemonic
  cmp dword [arg1_type], ARGTYPE_MEMORY
  je  .check_mnemonic
  cmp dword [segment_id], 0
  je  .check_mnemonic
  call write_segment_db  ;; Write db 0xSEGCODE in case we need to

  .check_mnemonic:
    cmp  dword [mnemonic], 0
    jne  .known_byte
    exec write_string, [asmfile_fd], s_db
    exec write_string, [asmfile_fd], space
    exec write_string, [asmfile_fd], hexstart
    exec write_hex, [asmfile_fd], [opcode], 8
    jmp  near .end
  .known_byte:
    ;; Mnemonic
    exec write_string, [asmfile_fd], [mnemonic]
    ;; Argument 1
    cmp dword [arg1_type], ARGTYPE_NONE
    je near .end
    exec write_string, [asmfile_fd], space
    PrintArguments arg1
    ;; Argument 2
    cmp dword [arg2_type], ARGTYPE_NONE
    je near .end
    exec write_string, [asmfile_fd], comma
    PrintArguments arg2
  .end:
    exec write_string, [asmfile_fd], nl
    ret

;; Writes the 'segment:', like ds:
write_segment:
  cmp dword [segment_id], 0
  je  .end
  exec write_string, [asmfile_fd], [segment_id]
  exec write_string, [asmfile_fd], colon
.end:
  ret

;; Writes 'db 0xREGCODE', like db 0x26.
write_segment_db:
  exec write_string, [asmfile_fd], s_db
  exec write_string, [asmfile_fd], space
  exec write_string, [asmfile_fd], hexstart
  cmp  dword [segment_id], SARGTYPE_REGES
  je   .write_db_es
  cmp  dword [segment_id], SARGTYPE_REGCS
  je   .write_db_cs
  cmp  dword [segment_id], SARGTYPE_REGSS
  je   .write_db_ss
  cmp  dword [segment_id], SARGTYPE_REGDS
  je   .write_db_ds
  jmp  .end
.write_db_es:
  exec write_hex, [asmfile_fd], 0x26, 8
  jmp .end
.write_db_cs:
  exec write_hex, [asmfile_fd], 0x2E, 8
  jmp .end
.write_db_ss:
  exec write_hex, [asmfile_fd], 0x36, 8
  jmp .end
.write_db_ds:
  exec write_hex, [asmfile_fd], 0x3E, 8
.end:
  exec write_string, [asmfile_fd], nl
  ret

_start:
  ;; Check arguments and exit if the command line is incorrect
  pop eax
  cmp eax, ARGC
  jne near .exit_usage

  ;; Skip the first argument (executable name) and get the file names
  pop eax
  pop dword [comfile_name]
  pop dword [asmfile_name]

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
    mov cl, [comfile+esi]
    mov [opcode], cl

    ;; Increment position counter
    inc esi

    call load_opcode_data
    call print_instruction

    jmp .main_loop
  .end_main_loop:

  ;; There may be a segment byte dangling around...
  cmp dword [segment_id], 0
  je  .no_seg_left
  call write_segment_db

.no_seg_left:
  ;; Close the files and exit
  sys_close [asmfile_fd]
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
