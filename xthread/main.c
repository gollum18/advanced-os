#include <stdio.h>
#include "proc.h"

extern void xmain();

struct xentry xtab[NPROC];
int currxid = 0;

void main(int argc, char * argv[]) {
	register struct xentry *xptr;
	struct xentry m;
	int i;
	int xidxmain;

	for (i = 0; i < NPROC; i++) {
		xptr = &xtab[i];
		xptr->xid = i;
		xptr->xlimit = malloc(STKSIZE);
		xptr->xbase = xptr->xlimit + STKSIZE - sizeof(WORD);
		xptr->xstate = XFREE;
	}

	xidxmain = xthread_create(xmain, 2, argc, argv);
	xtab[xidxmain].xstate = XRUN;
	ctxsw(m.xregs, xtab[xidxmain].xregs);
	/* never be here */
}
