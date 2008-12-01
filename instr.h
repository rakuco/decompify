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
ARGTYPE_NONE      db    0
ARGTYPE_CONST1    db    1
ARGTYPE_CONST3    db    2
ARGTYPE_REGAL     db    3
ARGTYPE_REGCL     db    4
ARGTYPE_REGDL     db    5
ARGTYPE_REGBL     db    6
ARGTYPE_REGAH     db    7
ARGTYPE_REGCH     db    8
ARGTYPE_REGDH     db    9
ARGTYPE_REGBH     db    10
ARGTYPE_REGAX     db    11
ARGTYPE_REGCX     db    12
ARGTYPE_REGDX     db    13
ARGTYPE_REGBX     db    14
ARGTYPE_REGSP     db    15
ARGTYPE_REGBP     db    16
ARGTYPE_REGSI     db    17
ARGTYPE_REGDI     db    18
ARGTYPE_REGES     db    19
ARGTYPE_REGCS     db    20
ARGTYPE_REGSS     db    21
ARGTYPE_REGDS     db    22
ARGTYPE_IMMED     db    23
ARGTYPE_MEMORY    db    24
ARGTYPE_REGMEM    db    25
ARGTYPE_REGISTER  db    26

;; Strings for the arguments that need it
SARGTYPE_CONST1     db    "1", 0
SARGTYPE_CONST3     db    "3", 0
SARGTYPE_REGAL      db    "al", 0
SARGTYPE_REGCL      db    "cl", 0
SARGTYPE_REGDL      db    "dl", 0
SARGTYPE_REGBL      db    "bl", 0
SARGTYPE_REGAH      db    "ah", 0
SARGTYPE_REGCH      db    "ch", 0
SARGTYPE_REGDH      db    "dh", 0
SARGTYPE_REGBH      db    "bh", 0
SARGTYPE_REGAX      db    "ax", 0
SARGTYPE_REGCX      db    "cx", 0
SARGTYPE_REGDX      db    "dx", 0
SARGTYPE_REGBX      db    "bx", 0
SARGTYPE_REGSP      db    "sp", 0
SARGTYPE_REGBP      db    "bp", 0
SARGTYPE_REGSI      db    "si", 0
SARGTYPE_REGDI      db    "di", 0
SARGTYPE_REGES      db    "es", 0
SARGTYPE_REGCS      db    "cs", 0
SARGTYPE_REGSS      db    "ss", 0
SARGTYPE_REGDS      db    "ds", 0
SARGTYPE_RM_BX_SI   db    "bx+si", 0
SARGTYPE_RM_BX_DI   db    "bx+di", 0
SARGTYPE_RM_BP_SI   db    "bx+si", 0
SARGTYPE_RM_BP_DI   db    "bx+si", 0
SARGTYPE_RM_SI      db    "si", 0
SARGTYPE_RM_DI      db    "di", 0
SARGTYPE_RM_BP      db    "bp", 0
SARGTYPE_RM_BX      db    "bx", 0

;; Pointers for groups of strings
ARRAY_CONSTARGS     dd    SARGTYPE_CONST1, SARGTYPE_CONST2
ARRAY_8BITREGS      dd    SARGTYPE_REGAL, SARGTYPE_REGCL, SARGTYPE_REGDL
                    dd    SARGTYPE_REGBL, SARGTYPE_REGAH, SARGTYPE_REGCH
                    dd    SARGTYPE_REGDH, SARGTYPE_REGBH
ARRAY_16BITREGS     dd    SARGTYPE_REGAX, SARGTYPE_REGCX, SARGTYPE_REGDX
                    dd    SARGTYPE_REGBX, SARGTYPE_REGSP, SARGTYPE_REGBP
                    dd    SARGTYPE_REGSI, SARGTYPE_REGDI
ARRAY_RM_MODES      dd    SARGTYPE_RM_BX_SI, SARGTYPE_RM_BX_DI, SARGTYPE_RM_BP_SI
                    dd    SARGTYPE_RM_BP_DI, SARGTYPE_RM_SI, SARGTYPE_RM_DI
                    dd    SARGTYPE_RM_BP, SARGTYPE_RM_BX

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
