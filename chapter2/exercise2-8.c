#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n);

int main(){
	unsigned x = 0x12345678;
	printf("%#010x\n",rightrot(x,33));
	return 0;
}

/*
returns value of x rotated to the right by n bit positons 
setup is for a 32 bit rotation
*/
unsigned rightrot(unsigned x, unsigned n){
	int count = 0;
	printf("rightrot: %#010x, %d\n", x, n);
	for(;n>0;--n){
		printf("%d\t%#010x\n",count++,x);
		if((x & 1) == 1){
			int rotBit = x << 31;
			x = (x >> 1) | rotBit;
		}else{
			x = x >> 1;
		}
	}
	return x;
}
