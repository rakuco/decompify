#!/usr/bin/env python
#
# MC404ABCD - 2008s2
# Projeto 2
#     decompify - COM files disassembler for Linux.
#
# 071294 - Jorge Augusto Hongo
# 072201 - Raphael Kubo da Costa
#
#     Copyright (C) 2008  Jorge Augusto Hongo
#     Copyright (C) 2008  Raphael Kubo da Costa
#
#     This program is free software: you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation, either version 3 of the License, or
#     (at your option) any later version.
#
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#
#     You should have received a copy of the GNU General Public License
#     along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

"""
opcodes2asm.py
  Convert opcodes.dat, obtained from Marius Gedminas' Disasm 1.0.0.
  Disasm 1.0.0 - http://gedmin.as/disasm

  This script was based on Marius' opasm.pl, but it's written in
  Python and generates output for NASM.
"""

import re
from sys import argv, exit

# There are repeated entries here because the arguments
# are different in decompify (addressing modes are separated).
#   args_dict = {'value': ['value_in_instr.h', is_16bits], ...}
args_dict = {
  'r/m8':   ['rm_both', False],
  'r/m16':  ['rm_both', True],
  'r8':     ['rm_register', False],
  'r16':    ['rm_register', True],
  'seg':    ['segment', True],
  'AL':     ['regal', False],
  'BL':     ['regbl', False],
  'CL':     ['regcl', False],
  'DL':     ['regdl', False],
  'AH':     ['regah', False],
  'BH':     ['regbh', False],
  'CH':     ['regch', False],
  'DH':     ['regdh', False],
  'AX':     ['regax', True],
  'BX':     ['regbx', True],
  'CX':     ['regcx', True],
  'DX':     ['regdx', True],
  'SP':     ['regsp', True],
  'BP':     ['regbp', True],
  'SI':     ['regsi', True],
  'DI':     ['regdi', True],
  'CS':     ['regcs', True],
  'DS':     ['regds', True],
  'SS':     ['regss', True],
  'ES':     ['reges', True],
  'mem8':   ['memory', False],
  'mem16':  ['memory', True],
  'mem32':  ['memory', True],
  'memoffs8':   ['rm_memory', False],
  'memoffs16':  ['rm_memory', True],
  'near':   ['near', True],   # XXX: not implemented yet
  'far':    ['far', True],    # XXX: not implemented yet
  'short':  ['short', True],  # XXX: not implemented yet
  'imm8':   ['immed', False],
  'imm16':  ['immed', True],
  'simm8':  ['simmed', True], # XXX: not implemented yet
  '1':      ['const1', True],
  '3':      ['const3', True],
  'prefix': ['none', True]
}

def parse_dat(datfile):
  opcode_re = re.compile(r"(?P<hexcode>[\da-fA-F]{2})\s+'?(?P<mnemonic>[\w<> ]+)'?(?:\s+(?P<arg1>[\w/]+)(?:,(?P<arg2>[\w/]+))?)?")
  groupstart_re = re.compile(r";\s*<(?P<groupname>[\w]+)>:")
  groupentry_re = re.compile(r";\s*[01]{3}(?:\s+'?(?P<mnemonic>[\w ]+)?'?\s*)")

  groups = {}
  mnemonics = set()
  opcodes = {}

  lines = datfile.readlines()

  while lines:
    line = lines.pop(0)

    # Normal line
    match = opcode_re.match(line)
    if match:
      opcode = int(match.group('hexcode'), 16)
      mnemonic = match.group('mnemonic').replace(' ', '_')
      opcodes[opcode] = {'mnemonic': mnemonic,
                         'arg1': match.group('arg1'),
                         'arg2': match.group('arg2')}

      if mnemonic and not mnemonic.startswith('<'):
        mnemonics.add(mnemonic)

      continue

    # Group start
    match = groupstart_re.match(line)
    if match:
      groupname = match.group('groupname')
      groups[groupname] = []

      # Read its 7 entries
      for i in range(8):
        groupmatch = groupentry_re.match(lines.pop(0))

        if groupmatch.group('mnemonic'):
          mnemonic = groupmatch.group('mnemonic').replace(' ', '_')
          groups[groupname].append(mnemonic)
          mnemonics.add(mnemonic)
        else:
          groups[groupname].append(None)

  return opcodes, mnemonics, groups

def print_groups(grptable):
  for group in grptable:
    print "ARRAY_GRP_%s \\" % group.upper()

    for element in grptable[group]:
      print "    dd ",

      if element:
        print 'I_' + element.upper()
      else:
        print '0'

def print_mnemonics(mnemonics):
  for m in sorted(list(mnemonics)):
    print "I_%s%sdb    \"%s\", 0" % (m.upper(), ' '*(15-len(m)), m.replace('_',
                                                                           ' '))

def print_opcodes(optable):
  for pos in range(256):
    print "  istruc Opcode%s; 0x%X" % (' '*35, pos)

    opcode = optable.get(pos, {'mnemonic': None, 'arg1': None, 'arg2': None})
    if opcode['mnemonic']:
      mn = 'I_' + opcode['mnemonic'].upper()
    else:
      mn = '0'

    # group
    if mn.startswith('I_<'):
      grp = 'ARRAY_GRP_' + mn[3:-1].upper()
      mn = '0'
    else:
      grp = '0'

    # segment_id
    seg = "0"

    if opcode['arg1']:
      addrmode = args_dict[opcode['arg1']]
      a1type = 'ARGTYPE_' + addrmode[0].upper()
      if addrmode[1]:
        a1reg = '1'
      else:
        a1reg = '0'
    else:
      a1type = 'ARGTYPE_NONE'
      a1reg  = '0'

    if opcode['arg2']:
      addrmode = args_dict[opcode['arg2']]
      a2type = 'ARGTYPE_' + addrmode[0].upper()
      if addrmode[1]:
        a2reg = '1'
      else:
        a2reg = '0'
    else:
      a2type = 'ARGTYPE_NONE'
      a2reg  = '0'

    print '    at Opcode.mnemonic,       dd ' + mn
    print '    at Opcode.group_id,       dd ' + grp
    print '    at Opcode.arg1_type,      dd ' + a1type
    print '    at Opcode.arg1_reg16bits, db ' + a1reg
    print '    at Opcode.arg2_type,      dd ' + a2type
    print '    at Opcode.arg2_reg16bits, db ' + a2reg

    print "  iend"

def opcodes2asm(datfile):
  """
  Main routine to generate the file. Calls the other functions
  that parse the DAT file and generate the opcodes structure.
  """

  # Header
  print "; MC404ABCD - 2008s2"
  print "; Projeto 2"
  print
  print "; This file was generated automatically by opcodes2asm.by"
  print
  print "%ifndef __OPCODES_H"
  print "%define __OPCODES_H"
  print
  print "%include \"instr.h\""
  print

  # Body
  optable, mnemonics, grptable = parse_dat(datfile)

  print ";; Mnemonics"
  print_mnemonics(mnemonics)

  print
  print ";; Opcodes"
  print "opcodes:"
  print_opcodes(optable)

  print
  print ";; Groups"
  print_groups(grptable)

  # Footer
  print
  print "%endif"
  print
  print "; vim:syntax=nasm"

if __name__ == "__main__":
  if len(argv) != 2:
    print "usage: opcodes2asm opcodes.dat"
    exit(2)

  try:
    datfile = open(argv[1])
  except IOError:
    print "error: could not open %s" % argv[1]
    exit(1)

  opcodes2asm(datfile)
