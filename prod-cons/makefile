CC=gcc
CFLAGS = -g
IFLAGS = -I.

.PHONY: clean depend

main: main.o client.o
	${CC} -pthread -o main main.o client.o

clean:
	rm main main.o

depend:
	makedepend ${IFLAGS} main.c client.c
# DO NOT DELETE

main.o: /usr/include/stdio.h /usr/include/string.h /usr/include/errno.h
main.o: /usr/include/features.h /usr/include/stdc-predef.h
main.o: /usr/include/pthread.h /usr/include/endian.h /usr/include/sched.h
main.o: /usr/include/time.h /usr/include/semaphore.h
client.o: /usr/include/pthread.h /usr/include/features.h
client.o: /usr/include/stdc-predef.h /usr/include/endian.h
client.o: /usr/include/sched.h /usr/include/time.h
