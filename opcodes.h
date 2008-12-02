; MC404ABCD - 2008s2
; Projeto 2

; This file was generated automatically by opcodes2asm.by

%ifndef __OPCODES_H
%define __OPCODES_H

%include "instr.h"

;; Mnemonics
I_AAA            db    "aaa", 0
I_AAD            db    "aad", 0
I_AAM            db    "aam", 0
I_AAS            db    "aas", 0
I_ADC            db    "adc", 0
I_ADD            db    "add", 0
I_AND            db    "and", 0
I_CALL           db    "call", 0
I_CBW            db    "cbw", 0
I_CLC            db    "clc", 0
I_CLD            db    "cld", 0
I_CLI            db    "cli", 0
I_CMC            db    "cmc", 0
I_CMP            db    "cmp", 0
I_CMPSB          db    "cmpsb", 0
I_CMPSW          db    "cmpsw", 0
I_CWD            db    "cwd", 0
I_DAA            db    "daa", 0
I_DAS            db    "das", 0
I_DEC            db    "dec", 0
I_DIV            db    "div", 0
I_HLT            db    "hlt", 0
I_IDIV           db    "idiv", 0
I_IMUL           db    "imul", 0
I_IN             db    "in", 0
I_INC            db    "inc", 0
I_INT            db    "int", 0
I_INTO           db    "into", 0
I_IRET           db    "iret", 0
I_JA             db    "ja", 0
I_JAE            db    "jae", 0
I_JB             db    "jb", 0
I_JBE            db    "jbe", 0
I_JCXZ           db    "jcxz", 0
I_JG             db    "jg", 0
I_JGE            db    "jge", 0
I_JL             db    "jl", 0
I_JLE            db    "jle", 0
I_JMP            db    "jmp", 0
I_JNO            db    "jno", 0
I_JNS            db    "jns", 0
I_JNZ            db    "jnz", 0
I_JO             db    "jo", 0
I_JPE            db    "jpe", 0
I_JPO            db    "jpo", 0
I_JS             db    "js", 0
I_JZ             db    "jz", 0
I_LAHF           db    "lahf", 0
I_LDS            db    "lds", 0
I_LEA            db    "lea", 0
I_LES            db    "les", 0
I_LOCK           db    "lock", 0
I_LODSB          db    "lodsb", 0
I_LODSW          db    "lodsw", 0
I_LOOP           db    "loop", 0
I_LOOPNZ         db    "loopnz", 0
I_LOOPZ          db    "loopz", 0
I_MOV            db    "mov", 0
I_MOVSB          db    "movsb", 0
I_MOVSW          db    "movsw", 0
I_MUL            db    "mul", 0
I_NEG            db    "neg", 0
I_NOP            db    "nop", 0
I_NOT            db    "not", 0
I_OR             db    "or", 0
I_OUT            db    "out", 0
I_POP            db    "pop", 0
I_POPF           db    "popf", 0
I_PUSH           db    "push", 0
I_PUSHF          db    "pushf", 0
I_RCL            db    "rcl", 0
I_RCR            db    "rcr", 0
I_REP            db    "rep", 0
I_REPNE          db    "repne", 0
I_RETF           db    "retf", 0
I_RETN           db    "retn", 0
I_ROL            db    "rol", 0
I_ROR            db    "ror", 0
I_SAHF           db    "sahf", 0
I_SAR            db    "sar", 0
I_SBB            db    "sbb", 0
I_SCASB          db    "scasb", 0
I_SCASW          db    "scasw", 0
I_SEGCS          db    "segcs", 0
I_SEGDS          db    "segds", 0
I_SEGES          db    "seges", 0
I_SEGSS          db    "segss", 0
I_SHL            db    "shl", 0
I_SHR            db    "shr", 0
I_STC            db    "stc", 0
I_STD            db    "std", 0
I_STI            db    "sti", 0
I_STOSB          db    "stosb", 0
I_STOSW          db    "stosw", 0
I_SUB            db    "sub", 0
I_TEST           db    "test", 0
I_WAIT           db    "wait", 0
I_XCHG           db    "xchg", 0
I_XLAT           db    "xlat", 0
I_XOR            db    "xor", 0

;; Opcodes
opcodes:
  istruc Opcode                                   ; 0x0
    at Opcode.mnemonic,       dd I_ADD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x1
    at Opcode.mnemonic,       dd I_ADD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x2
    at Opcode.mnemonic,       dd I_ADD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x3
    at Opcode.mnemonic,       dd I_ADD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x4
    at Opcode.mnemonic,       dd I_ADD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5
    at Opcode.mnemonic,       dd I_ADD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x6
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGES
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGES
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x8
    at Opcode.mnemonic,       dd I_OR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9
    at Opcode.mnemonic,       dd I_OR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xA
    at Opcode.mnemonic,       dd I_OR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB
    at Opcode.mnemonic,       dd I_OR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xC
    at Opcode.mnemonic,       dd I_OR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD
    at Opcode.mnemonic,       dd I_OR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xE
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCS
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x10
    at Opcode.mnemonic,       dd I_ADC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x11
    at Opcode.mnemonic,       dd I_ADC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x12
    at Opcode.mnemonic,       dd I_ADC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x13
    at Opcode.mnemonic,       dd I_ADC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x14
    at Opcode.mnemonic,       dd I_ADC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x15
    at Opcode.mnemonic,       dd I_ADC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x16
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSS
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x17
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSS
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x18
    at Opcode.mnemonic,       dd I_SBB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x19
    at Opcode.mnemonic,       dd I_SBB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x1A
    at Opcode.mnemonic,       dd I_SBB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x1B
    at Opcode.mnemonic,       dd I_SBB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x1C
    at Opcode.mnemonic,       dd I_SBB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x1D
    at Opcode.mnemonic,       dd I_SBB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x1E
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDS
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x1F
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDS
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x20
    at Opcode.mnemonic,       dd I_AND
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x21
    at Opcode.mnemonic,       dd I_AND
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x22
    at Opcode.mnemonic,       dd I_AND
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x23
    at Opcode.mnemonic,       dd I_AND
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x24
    at Opcode.mnemonic,       dd I_AND
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x25
    at Opcode.mnemonic,       dd I_AND
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x26
    at Opcode.mnemonic,       dd I_SEGES
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x27
    at Opcode.mnemonic,       dd I_DAA
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x28
    at Opcode.mnemonic,       dd I_SUB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x29
    at Opcode.mnemonic,       dd I_SUB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x2A
    at Opcode.mnemonic,       dd I_SUB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x2B
    at Opcode.mnemonic,       dd I_SUB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x2C
    at Opcode.mnemonic,       dd I_SUB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x2D
    at Opcode.mnemonic,       dd I_SUB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x2E
    at Opcode.mnemonic,       dd I_SEGCS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x2F
    at Opcode.mnemonic,       dd I_DAS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x30
    at Opcode.mnemonic,       dd I_XOR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x31
    at Opcode.mnemonic,       dd I_XOR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x32
    at Opcode.mnemonic,       dd I_XOR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x33
    at Opcode.mnemonic,       dd I_XOR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x34
    at Opcode.mnemonic,       dd I_XOR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x35
    at Opcode.mnemonic,       dd I_XOR
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x36
    at Opcode.mnemonic,       dd I_SEGSS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x37
    at Opcode.mnemonic,       dd I_AAA
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x38
    at Opcode.mnemonic,       dd I_CMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x39
    at Opcode.mnemonic,       dd I_CMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x3A
    at Opcode.mnemonic,       dd I_CMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x3B
    at Opcode.mnemonic,       dd I_CMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x3C
    at Opcode.mnemonic,       dd I_CMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x3D
    at Opcode.mnemonic,       dd I_CMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x3E
    at Opcode.mnemonic,       dd I_SEGDS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x3F
    at Opcode.mnemonic,       dd I_AAS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x40
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x41
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x42
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x43
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x44
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x45
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x46
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x47
    at Opcode.mnemonic,       dd I_INC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x48
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x49
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x4A
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x4B
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x4C
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x4D
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x4E
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x4F
    at Opcode.mnemonic,       dd I_DEC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x50
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x51
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x52
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x53
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x54
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x55
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x56
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x57
    at Opcode.mnemonic,       dd I_PUSH
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x58
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x59
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5A
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5B
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5C
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5D
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5E
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x5F
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x60
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x61
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x62
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x63
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x64
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x65
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x66
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x67
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x68
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x69
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x6A
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x6B
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x6C
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x6D
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x6E
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x6F
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x70
    at Opcode.mnemonic,       dd I_JO
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x71
    at Opcode.mnemonic,       dd I_JNO
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x72
    at Opcode.mnemonic,       dd I_JB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x73
    at Opcode.mnemonic,       dd I_JAE
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x74
    at Opcode.mnemonic,       dd I_JZ
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x75
    at Opcode.mnemonic,       dd I_JNZ
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x76
    at Opcode.mnemonic,       dd I_JBE
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x77
    at Opcode.mnemonic,       dd I_JA
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x78
    at Opcode.mnemonic,       dd I_JS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x79
    at Opcode.mnemonic,       dd I_JNS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7A
    at Opcode.mnemonic,       dd I_JPE
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7B
    at Opcode.mnemonic,       dd I_JPO
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7C
    at Opcode.mnemonic,       dd I_JL
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7D
    at Opcode.mnemonic,       dd I_JGE
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7E
    at Opcode.mnemonic,       dd I_JLE
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x7F
    at Opcode.mnemonic,       dd I_JG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x80
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_AROP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x81
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_AROP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x82
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x83
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_AROP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_SIMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x84
    at Opcode.mnemonic,       dd I_TEST
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x85
    at Opcode.mnemonic,       dd I_TEST
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x86
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x87
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x88
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x89
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x8A
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x8B
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x8C
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_SEGMENT
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x8D
    at Opcode.mnemonic,       dd I_LEA
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_MEMORY
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x8E
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SEGMENT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x8F
    at Opcode.mnemonic,       dd I_POP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x90
    at Opcode.mnemonic,       dd I_NOP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x91
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGCX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x92
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGDX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x93
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGBX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x94
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGSP
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x95
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGBP
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x96
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGSI
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x97
    at Opcode.mnemonic,       dd I_XCHG
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGDI
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0x98
    at Opcode.mnemonic,       dd I_CBW
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x99
    at Opcode.mnemonic,       dd I_CWD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9A
    at Opcode.mnemonic,       dd I_CALL
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_FAR
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9B
    at Opcode.mnemonic,       dd I_WAIT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9C
    at Opcode.mnemonic,       dd I_PUSHF
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9D
    at Opcode.mnemonic,       dd I_POPF
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9E
    at Opcode.mnemonic,       dd I_SAHF
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0x9F
    at Opcode.mnemonic,       dd I_LAHF
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA0
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_RM_MEMORY
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA1
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_RM_MEMORY
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xA2
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_MEMORY
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_REGAL
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA3
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_MEMORY
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGAX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xA4
    at Opcode.mnemonic,       dd I_MOVSB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA5
    at Opcode.mnemonic,       dd I_MOVSW
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA6
    at Opcode.mnemonic,       dd I_CMPSB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA7
    at Opcode.mnemonic,       dd I_CMPSW
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA8
    at Opcode.mnemonic,       dd I_TEST
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xA9
    at Opcode.mnemonic,       dd I_TEST
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xAA
    at Opcode.mnemonic,       dd I_STOSB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xAB
    at Opcode.mnemonic,       dd I_STOSW
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xAC
    at Opcode.mnemonic,       dd I_LODSB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xAD
    at Opcode.mnemonic,       dd I_LODSW
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xAE
    at Opcode.mnemonic,       dd I_SCASB
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xAF
    at Opcode.mnemonic,       dd I_SCASW
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB0
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB1
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB2
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB3
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB4
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB5
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB6
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB7
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xB8
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xB9
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGCX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xBA
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xBB
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xBC
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xBD
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGBP
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xBE
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGSI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xBF
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDI
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xC0
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xC1
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xC2
    at Opcode.mnemonic,       dd I_RETN
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xC3
    at Opcode.mnemonic,       dd I_RETN
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xC4
    at Opcode.mnemonic,       dd I_LES
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_MEMORY
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xC5
    at Opcode.mnemonic,       dd I_LDS
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_RM_REGISTER
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_MEMORY
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xC6
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_MEMORY
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xC7
    at Opcode.mnemonic,       dd I_MOV
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_MEMORY
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xC8
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xC9
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xCA
    at Opcode.mnemonic,       dd I_RETF
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xCB
    at Opcode.mnemonic,       dd I_RETF
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xCC
    at Opcode.mnemonic,       dd I_INT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_CONST3
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xCD
    at Opcode.mnemonic,       dd I_INT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xCE
    at Opcode.mnemonic,       dd I_INTO
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xCF
    at Opcode.mnemonic,       dd I_IRET
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD0
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_SHFOP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_CONST1
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xD1
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_SHFOP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_CONST1
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xD2
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_SHFOP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_REGCL
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD3
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_SHFOP
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGCL
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD4
    at Opcode.mnemonic,       dd I_AAM
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD5
    at Opcode.mnemonic,       dd I_AAD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD6
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD7
    at Opcode.mnemonic,       dd I_XLAT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD8
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xD9
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xDA
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xDB
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xDC
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xDD
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xDE
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xDF
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE0
    at Opcode.mnemonic,       dd I_LOOPNZ
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE1
    at Opcode.mnemonic,       dd I_LOOPZ
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE2
    at Opcode.mnemonic,       dd I_LOOP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE3
    at Opcode.mnemonic,       dd I_JCXZ
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE4
    at Opcode.mnemonic,       dd I_IN
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE5
    at Opcode.mnemonic,       dd I_IN
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_IMMED
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE6
    at Opcode.mnemonic,       dd I_OUT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_REGAL
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE7
    at Opcode.mnemonic,       dd I_OUT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_IMMED
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_REGAX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xE8
    at Opcode.mnemonic,       dd I_CALL
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NEAR
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xE9
    at Opcode.mnemonic,       dd I_JMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NEAR
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xEA
    at Opcode.mnemonic,       dd I_JMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_FAR
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xEB
    at Opcode.mnemonic,       dd I_JMP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_SHORT
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xEC
    at Opcode.mnemonic,       dd I_IN
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAL
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_REGDX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xED
    at Opcode.mnemonic,       dd I_IN
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGAX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGDX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xEE
    at Opcode.mnemonic,       dd I_OUT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGAL
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xEF
    at Opcode.mnemonic,       dd I_OUT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_REGDX
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_REGAX
    at Opcode.arg2_reg16bits, db 1
  iend
  istruc Opcode                                   ; 0xF0
    at Opcode.mnemonic,       dd I_LOCK
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF1
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF2
    at Opcode.mnemonic,       dd I_REPNE
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF3
    at Opcode.mnemonic,       dd I_REP
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF4
    at Opcode.mnemonic,       dd I_HLT
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF5
    at Opcode.mnemonic,       dd I_CMC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF6
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_GRP1
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF7
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_GRP1
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF8
    at Opcode.mnemonic,       dd I_CLC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xF9
    at Opcode.mnemonic,       dd I_STC
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xFA
    at Opcode.mnemonic,       dd I_CLI
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xFB
    at Opcode.mnemonic,       dd I_STI
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xFC
    at Opcode.mnemonic,       dd I_CLD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xFD
    at Opcode.mnemonic,       dd I_STD
    at Opcode.mnem_group,     dd 0
    at Opcode.arg1_type,      dd ARGTYPE_NONE
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xFE
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_GRP2
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 0
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend
  istruc Opcode                                   ; 0xFF
    at Opcode.mnemonic,       dd 0
    at Opcode.mnem_group,     dd GRP_GRP3
    at Opcode.arg1_type,      dd ARGTYPE_RM_BOTH
    at Opcode.arg1_reg16bits, db 1
    at Opcode.arg2_type,      dd ARGTYPE_NONE
    at Opcode.arg2_reg16bits, db 0
  iend

%endif

; vim:syntax=nasm
