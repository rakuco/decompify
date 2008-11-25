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

%ifndef __MATH_H
%define __MATH_H

;; mult (int a, int b)
;;   Multiplies a and by and stores the result in eax (preserves ecx and edx)
%macro mult 2
  push edx
  push ecx
  mov eax, %1
  mov ecx, %2
  mul ecx
  pop ecx
  pop edx
%endmacro

;; mult (int a, int b, int *result)
;;   *result = a*b
;;
;;   This macro calls mult(a, b) and stores the result in its third argument.
%macro mult 3
  mult %1, %2
  mov %3, eax
%endmacro

%endif

; vim:syntax=nasm
