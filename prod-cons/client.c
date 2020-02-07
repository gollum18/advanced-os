#include <pthread.h>

#define BUFSIZE 8

static int buffer[BUFSIZE];
static int bufin = 0;
static int bufout = 0;
static pthread_mutex_t buffer_lock = PTHREAD_MUTEX_INITIALIZER;

/* Get the next item from buffer and put it in *itemp */
void get_item(int * itemp) {
	pthread_mutex_lock(&buffer_lock);
	*itemp = buffer[bufout];
	bufout = (bufout + 1) & BUFSIZE;
	pthread_mutex_unlock(&buffer_lock);
	return;
}

/* Put item into buffer at position bufin and update bufin */
void put_item(int item) {
	pthread_mutex_lock(&buffer_lock);
	buffer[bufin] = item;
	bufin = (bufin + 1) % BUFSIZE;
	pthread_mutex_unlock(&buffer_lock);
	return;
}
