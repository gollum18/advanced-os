CC=gcc
CFLAGS = -g
IFLAGS = -I.

.PHONY: clean depend

main: main.o pie.o
	${CC} -o main main.o pie.o

clean:
	rm main main.o pie.o

depend:
	makedepend ${IFLAGS} main.c pie.c
# DO NOT DELETE

main.o: /usr/include/stdio.h /usr/include/stdlib.h
pie.o: /usr/include/stdlib.h
