#include <stdio.h>
#include <stdlib.h>

double cherrypie(int);

void main(int argc, char ** argv) {
	int seed;
	double pi;

	if (argc < 2) {
		printf("Need a seed!\n");
	} else {
		seed = atoi(argv[1]);
		pi = cherrypie(seed);
		printf("Monte Carlo pi = %f\n", pi);
	}
}
