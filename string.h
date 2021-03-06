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

%ifndef __STRING_H
%define __STRING_H

%include "util.h"

;; printnl(void)
;;   Prints a new line character
%define   printnl print_string(nl)

;; print_string(char *s)
;;   Writes s to stdout
%define   print_string(s) exec write_string, STDOUT, s

HexCharacters   db "0123456789abcdef"

colon           db  ':', 0
comma           db  ',', 0
hexstart        db  '0x', 0
memend          db  ']', 0
memstart        db  '[', 0
minus           db  '-', 0
nl              db  0x0A, 0
plus            db  '+', 0
space           db  ' ', 0

s_byte          db  'byte', 0
s_db            db  'db', 0
s_dollar        db  '$', 0
s_far           db  'far', 0
s_near          db  'near', 0
s_word          db  'word', 0

%endif

; vim:syntax=nasm
