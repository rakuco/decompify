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

section .text
  global get_file_size

;; get_file_size (int fd)
;;   Returns the total size of the file in bytes in eax.
get_file_size:
  push ebp
  mov ebp, esp

  push esi

  ; Save current file position
  sys_lseek [ebp+8], 0, SEEK_CUR
  push eax

  ; Get the file size
  sys_lseek [ebp+8], 0, SEEK_END
  mov esi, eax

  ; Seek back to the original position
  pop eax
  sys_lseek [ebp+8], eax, SEEK_SET

  ; Return the file size in eax
  mov eax, esi

  pop esi

  pop ebp
  ret

; vim:syntax=nasm
