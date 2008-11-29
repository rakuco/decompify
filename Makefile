#
# MC404 - 2008s2
# Projeto 2
#   decompify - COM files disassembler for Linux
#
# 071294 - Jorge Augusto Hongo
# 072201 - Raphael Kubo da Costa
#

AS=nasm
ASFLAGS=-f elf -g
LD=ld

EXE=decompify
OBJS=main.o disasm.o file.o
SRCS=main.asm disasm.asm file.asm

.SUFFIXES: .asm .o

.asm.o:
	$(AS) $(ASFLAGS) $<

$(EXE): $(OBJS)
	$(LD) -o $@ $(OBJS)

all: $(EXE)

clean:
	rm -f $(EXE) $(OBJS)
