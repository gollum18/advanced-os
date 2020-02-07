#ifndef __PROC__
#define __PROC__

#include <stdio.h>
#include <stdlib.h>

typedef int WORD;

// Thread stack defines
#define PNREGS 5
#define NPROC 10
#define SP 0

// Thread state
#define XFREE 0
#define XREADY 1
#define XRUN 2

// Thread entry
struct xentry {
	int xid;
	WORD xregs[PNREGS];
	WORD xbase;
	WORD xlimit;
	WORD xstate;
};

#define STKSIZE 8192

extern struct xentry xtab[];
extern int currxid;

#endif
