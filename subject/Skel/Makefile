# Programmation - EPITA SPE
# TP Note
# Makefile

# How many questions ?

QNUM:=13

# Almost generic

CC=gcc
CPPFLAGS= -D_GNU_SOURCE -include cheaters.h -include stdint.h \
	  -include stdlib.h -include skel.h
CFLAGS=   -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS=

QNUMS:= $(shell seq --format=%02g 1 ${QNUM})

QUESTIONS= $(foreach num, ${QNUMS}, question${num})

all: ${QUESTIONS}

question%: base_test.o question%.o test_q%.o
	${CC} ${LDFLAGS} -o $@ $^ ${LDLIBS}

# Common rules

files-list: ../build_files
	rm -f $@
	../build_files ${QUESTIONS} > $@

clean::
	rm -f *~
	rm -f *.o
	rm -f ${QUESTIONS} files-list

#
# END
#
