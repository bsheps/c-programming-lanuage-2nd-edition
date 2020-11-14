#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
int main(){
	unsigned x = 0252;
	printf("%o\n", invert(x,4,3));
	return 0;
}
/*
returns x with the n bits that begin at positon p inverted, rest is unchanged
*/
unsigned invert(unsigned x, int p, int n){
	return x ^ ((~(~0 << n)) << (p+1-n));
}

