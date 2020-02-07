#include <stdio.h>
#include "proc.h"

void userret() {
	xtab[currxid].xstate = XFREE;
	printf("XT: Old threads never die; they just fade away. (id:%d)\n", currxid);
	resched();
}

static int newxid() {
	int i, xid;
	static int nextproc = 0;

	for (i = 0; i < NPROC; i++) {
		xid = nextproc;
		if ((++nextproc) >= NPROC) {
			nextproc = 0;
		}
		if (xtab[xid].xstate == XFREE) {
			return xid;
		}
	}
	
	printf("Error: process table is full!\n");
	exit(1);
}

int xthread_create(int * procaddr, int nargs, int args) {
	WORD * saddr;
	WORD * ap;
	struct xentry * xptr;
	int xid;

	xid = newxid();

	xptr = &xtab[xid];
	xptr->xstate = XREADY;

	saddr = (WORD *) xptr->xbase;

	ap = (&args) + nargs;
	for(; nargs > 0; nargs--) {
		*(--saddr) = *(--ap);
	}
	*(--saddr) = (int)userret;
	*(--saddr) = (int)procaddr;
	--saddr;
	saddr -= 2;
	xptr->xregs[SP] = (int) saddr;

	return xid;
}


