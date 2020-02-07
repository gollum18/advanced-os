#include <stdio.h>
#include "proc.h"

int resched() {
	register struct xentry *cptr;
	register struct xentry *xptr;
	int i, next;

	cptr = &xtab[currxid];

	next = currxid;
	for (i = 0; i < NPROC; i++) {
		if ((++next) >= NPROC) {
			next = 0;
		}
		if (xtab[next].xstate == XREADY) {
			xtab[next].xstate = XRUN;
			xptr = &xtab[next];
			currxid = next;
			ctxsw(cptr->xregs, xptr->xregs);
			return;
		}
	}

	printf("XT: no threads to run!\n");
	exit(0);
}
