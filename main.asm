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

%include "syscalls.h"

;; Number of command line arguments
%define ARGC              3

section .bss
  ;; Files (input and output)
  asmfile_fd                resw    2
  asmfile_name              resb    255
  comfile_fd                resw    2
  comfile_name              resb    255


section .data
  ;; Error messages
  open_input_file_msg       db      "Erro ao abrir arquivo executavel", 0x0A, 0
  open_input_file_msg_len   equ     $-open_input_file_msg
  open_output_file_msg      db      "Erro ao abrir arquivo de saida", 0x0A, 0
  open_output_file_msg_len  equ     $-open_output_file_msg
  usage_msg                 db      "Uso: ./decompify executavel.com output.asm", 0x0A, 0
  usage_msg_len             equ     $-usage_msg


section .text
  extern disasm_write_header
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

  ;; Open the files, exit on error
  sys_open [comfile_name]
  cmp eax, -1
  jle .exit_open_input_file
  mov [comfile_fd], eax

  sys_open [asmfile_name], O_WRONLY|O_TRUNC|O_CREAT
  cmp eax, -1
  jle .exit_open_output_file
  mov [asmfile_fd], eax

  ;; Write the code header
  push dword [asmfile_fd]
  call disasm_write_header

  ;; Close the files and exit
  sys_close [comfile_fd]
  sys_close [asmfile_fd]
  sys_exit EX_OK

.exit_open_input_file:
  sys_write STDOUT, open_input_file_msg, open_input_file_msg_len
  sys_exit EX_DATAERR

.exit_open_output_file:
  sys_close [comfile_fd]
  sys_write STDOUT, open_output_file_msg, open_output_file_msg_len
  sys_exit EX_DATAERR

.exit_usage:
  sys_write STDOUT, usage_msg, usage_msg_len
  sys_exit  EX_USAGE

; vim:syntax=nasm:
