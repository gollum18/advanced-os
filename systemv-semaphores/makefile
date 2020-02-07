CC=gcc
CFLAGS = -g
IFLAGS = -I.

.PHONY: clean depend

semaphorev: semaphorev.o
	${CC} -o semaphorev semaphorev.o

clean:
	rm semaphorev semaphorev.o

depend:
	makedepend ${IFLAGS} semaphorev.c
# DO NOT DELETE

semaphorev.o: /usr/include/stdio.h
