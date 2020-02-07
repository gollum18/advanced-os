.DEFAULT:
	co -q $@

HFILES = proc.h
CFILES = create.c yield.c resched.c main.c
SFILES = ctxsw.s
OFILES = create.o ctxsw.o yield.o resched.o main.o
XTLIB = ./libxt.a
APP_CFILES = xmain.c
APP_OFILES = xmain.o

IFLAGS = -g -I. -I./usr/lib/gcc/x86_64-linux-gnu/7/include
CFLAGS = ${IFLAGS}
DEPFLAGS = ${IFLAGS}
CC = gcc -m32
AS = as -32

RCS = makefile ${HFILES} ${CFILES}

a.out: ${XTLIB} ${APP_OFILES}
	${CC} ${CFLAGS} ${APP_OFILES} ${XTLIB}

${XTLIB}: ${OFILES}
	ar cr ${XTLIB} ${OFILES}

ci:
	ci -i ${RCS}

clean:
	rm -f ${OFILES} ${APP_OFILES} a.out

depend:
	makedepend ${DEPFLAGS} ${CFLAGS} ${SFILES}
# DO NOT DELETE
