#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
};

#define SEMKEY 9876
int semkey;

// Lock
void P(int semaphore) {
	struct sembuf psembuf;

	psembuf.sem_op = -1;
	psembuf.sem_flg = 0;
	psembuf.sem_num = semaphore;
	semop(semkey, &sembuf, 1);
	return;
}

// Unlock
void V(int semaphore) {
	struct sembuf vsembuf;

	vsembuf.sem_op = 1;
	vsembuf.sem_flg = 0;
	vsembuf.sem_num = semaphore;
	semop(semkey, &vsembuf, 1);
	return;
}

void child() {
	int pid=getpid();
	printf("Child process %d is starting up...\n", pid);
	fflush(stdout);
	P(0);
	printf("Child process %d has cleared the semaphore!\n", pid);
	fflush(stdout);
	exit(0);
}

void main(void) {
	int pid1, pid2;
	short seminit[1];
	union semun semctlarg;

	semkey = semget(SEMKEY, 1, 0777|IPC_CREAT);
	seminit[0] = 0;
	semctlarg.array = seminit;
	semctl(semkey, 1, SETALL, semctlarg);

	if ((pid1=fork()) == 0) {
		child();
	}
	if ((pid2=fork()) == 0) {
		child();
	}

	printf("Child processes are %d and %d.\n", pid1, pid2);
	printf("Parent process is now waiting a while.\n");
	fflush(stdout);
	sleep(3);
	printf("Parent is not signalling the semaphore...\n");

	fflush(stdout);
	V(0);
	sleep(3);
	printf("Parent is not signalling the semaphore...\n");
	fflush(stdout);
	V(0);

	printf("Parent is now waiting for the children to exit.\n");
	fflush(stdout);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	printf("Children have exited. Cleaning up...\n");
	semctl(semkey, 1, IPC_RMID, 0);
}
