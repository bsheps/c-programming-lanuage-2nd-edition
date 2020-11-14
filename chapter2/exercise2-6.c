#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
int main(){
	unsigned x = 0252;
	unsigned y = 017;
	unsigned z = 00;
	printf("%o\n", setbits(x,4,3,y));
	printf("%o\n", setbits(x,4,3,z));
	return 0;
}

/*
returns x with the n-bits that begin at position p set to the rightmost n bits
of y.
*/
unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned nBitsCleared = x & (~((~(~0 << n)) << (p+1-n)));
	unsigned yBitsToInsert =  ((~(~0 << n )) & y) << (p+1-n);
	return nBitsCleared | yBitsToInsert;
}
