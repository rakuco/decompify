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

%ifndef __UTIL_H
%define __UTIL_H

;; exec(function, arg1, arg2, ..., argN)
;;   Calls the procedure function.
;;   It first passes the arguments according to the
;;   C calling convention (argN down to arg1), and
;;   after the call it removes them from the stack.
;;
%macro exec 2-*
  %rep %0-1
    %rotate -1
    push dword %1
  %endrep
  %rotate -1

  call %1
  add  esp, 4*(%0-1)
%endmacro

%endif

; vim:syntax=nasm:
