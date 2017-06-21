#include <stdlib.h>
#include <stdio.h>

typedef struct NODE{
	struct NODE *fwd;
	struct NODE *bwd;;
	int value;
} Node;


