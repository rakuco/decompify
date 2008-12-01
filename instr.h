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

%ifndef __INSTR_H
%define __INSTR_H

;; Argument types (immed, r/m etc)
ARGTYPE_NONE      db    1<<0
ARGTYPE_CONST1    db    1<<1
ARGTYPE_CONST3    db    1<<2
ARGTYPE_IMMED     db    1<<3
ARGTYPE_MEMORY    db    1<<4
ARGTYPE_REGMEM    db    1<<5
ARGTYPE_REGISTER  db    1<<6

;; Instruction list (for now, here)
I_ADD             db    "add", 0

struc Opcode
  .mnemonic:      resd    1
  .reg16bits:     resb    1
  .type_arg1:     resd    1
  .type_arg2:     resd    1
endstruc

opcodes:
  istruc Opcode
    at Opcode.mnemonic,  dd I_ADD
    at Opcode.reg16bits, db 0
    at Opcode.type_arg1, dd ARGTYPE_REGMEM
    at Opcode.type_arg2, dd ARGTYPE_REGISTER
  iend

%endif

; vim:syntax=nasm:
