#include <stdio.h>
#include <stdlib.h>

static int *tabs;

int main(int argc, char *argv[]){
	int mem[argc];
	int *t = mem;
	tabs = t;
	// I thought *t++ = atoi(*++argv) was causing undefined behavior, but after
	// further research I think my bug was originating in allocating memory in
	// a helper function. After the function closed, the memory allocated did
	// not always persist. Thus, causing a weird undefined bug.
	while(--argc >= 1)
		*t++ = atoi(*++argv);
	*t = 0; // set last item to 0
	for(;*tabs; tabs++)
		printf("%d ", *tabs);
	return 0;
}

