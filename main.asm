;;
;; MC404ABCD - 2008s2
;; Projeto 2
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

section .data
  ;; Error messages
  usage_msg                     db      "Uso: ./prj2 executavel.com output.asm", 0x0A, 0
  usage_msg_len                 equ     $-usage_msg

section .text
  global _start

_start:
  ;; Check arguments and exit if the command line is incorrect
  pop eax
  cmp eax, ARGC
  jne near .exit_usage

  sys_exit EX_OK

.exit_usage:
  sys_write STDOUT, usage_msg, usage_msg_len
  sys_exit  EX_USAGE

; vim:syntax=nasm:
