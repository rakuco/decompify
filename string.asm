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

%include "string.h"
%include "syscalls.h"
%include "util.h"

section .text
  global strlen, write_hex, write_string

;; int strlen(char *s)
;;   Gets the length of a null-terminated string.
;;
;; Out:       eax (length of the string)
;; Destroys:  eax
;;
strlen:
  push ebp
  mov  ebp, esp

  push ecx
  push edi

  mov  edi, [ebp+8]
  xor  ecx, ecx
  not  ecx
  xor  al, al

  cld
  repne scasb
  not ecx
  lea eax, [ecx-1]

  pop edi
  pop ecx
  pop ebp

  ret

;; write_hex (int fd, char *s, size_t elemsize)
;;   Writes a hexadecimal byte/word/dword to fd.
;;   This procedure was written by Christian Fowelin <christian@fowelin.de>
;;   for libASM - http://www.fowelin.de/christian/computer/libASM
write_hex:
  push ebp
  mov ebp, esp
  push eax
  push ebx
  push ecx
  push edx
  push esi

  mov edx, [ebp+16]
  mov esi, [ebp+12]
  mov ebx, [ebp+8]

  and edx, 0xFF
  cmp edx, 32
  jnae .j0
  mov edx, 32
.j0:
  mov ecx, 32
  sub ecx, edx
  shl esi, cl
.j1:
  shld ecx, esi, 4
  shl esi, 4
  and ecx, 0x0F
  add ecx, dword HexCharacters
  sys_write ebx, ecx, 1
  sub edx, byte 4
  jnz .j1

  pop esi
  pop edx
  pop ecx
  pop ebx
  pop eax
  pop ebp
  ret

;; write_string(int fd, char *s)
;;   Writes s to file descriptor fd.
;;
write_string:
  push ebp
  mov  ebp, esp

  push edi
  push eax

  exec strlen, [ebp+12]
  mov  edi, eax

  sys_write [ebp+8], [ebp+12], edi

  pop eax
  pop edi
  pop ebp
  ret


; vim:syntax=nasm:
