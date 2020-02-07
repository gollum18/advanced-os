#include <stdio.h>
#include "proc.h"

void xthread_yield(int xid) {
	struct xentry *cptr, *xptr;

	cptr = &xtab[currxid];
	cptr->xstate = XREADY;
	xptr = &xtab[xid];
	xptr->xstate = XRUN;

	currxid = xid;

	ctxsw(cptr->xregs, xptr->xregs);
}
