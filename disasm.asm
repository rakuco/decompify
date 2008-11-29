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

;; Texts and messages
section .data
  header_msg  db "; MC404ABCD - 2008s2", 0x0A,
              db ";   Projeto 2 - Grupo 30", 0x0A,
              db "; COM file disassembled by decompify v0.0.1", 0x0A,
              db "; see http://github.com/rakuco/decompify", 0x0A, 0X0A,

              db "org 0x100", 0x0A, 0x0A

              db "start:", 0x0A, 0
  header_len  equ $-header_msg

section .text
  global disasm_write_header

;; disasm_write_header (void)
;;   Writes a small header present in every disassembled file.
;;   This header contains a comment telling the version of the program
;;   and also the ORG 0x100 and 'start:' parts of the code.
disasm_write_header:
  push ebp
  mov ebp, esp

  sys_write [ebp+8], header_msg, header_len

  pop ebp
  ret

; vim:syntax=nasm:
