#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#define SUMSIZE 100
#define BUFSIZE 8

int sum = 0;
sem_t items;
sem_t slots;

void put_item(int);
void get_item(int *);

static void * producer() {
	int i;

	for (i = 0; i <= SUMSIZE; i++) {
		sem_wait(&slots);
		put_item(i*i);
		sem_post(&items);
	}
	
	return NULL;
}

static void * consumer(void * arg2) {
	int i, myitem;

	for (i = 1; i <= SUMSIZE; i++) {
		sem_wait(&items);
		get_item(&myitem);
		sem_post(&slots);
		sum += myitem;
	}

	return NULL;
}

void main(void) {
	pthread_t prodtid;
	pthread_t constid;
	int i, total;

	total = 0;
	for (i = 1; i <= SUMSIZE; i++) {
		total += i*i;
	}
	printf("The checksum is %d\n", total);

	sem_init(&items, 0, 0);
	sem_init(&slots, 0, BUFSIZE);

	pthread_create(&prodtid, NULL, producer, NULL);
	pthread_create(&constid, NULL, consumer, NULL);

	pthread_join(prodtid, NULL);
	pthread_join(constid, NULL);
	printf("The threads produced the sum %d\n", sum);
}
