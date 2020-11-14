/*
expression x &= (x-1) deletes the rightmost 1-bit
Why?
Examples:
if x = 1111 or 15

For odd numbers
  1111
-    1
------
  1110 & 1111 = 1110

For even numbers
x=1110

  1110
-    1
------
  1101 & 1110 = 1100

x=1000

  1000
-    1
------
  0110 & 1000 = 0000

x=1010
  
  1010
-    1
------
  1000 & 1010 = 1000

This works because the 1 must be deleted, if the 1 does not exist in the first
bit, then the first 1 bit from left to right must carry down (leaving a trail
of 1 bits behind it). That trail of 1 bits gets removed during the AND 
operation since 0 & 1 = 0.

*/

#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);

int main(){
	int i;
	for(i=0; i < 0xFFFFFF; ++i){
		bitcount2(i);
	}
	return 0;
}

// original from p50
// Ave time: (1.931 +1.730 + 1.751) / 3 = 1.804
int bitcount(unsigned x){
	int b;

	for (b=0; x !=0; x>>= 1)
		if(x & 01)
			b++;
	return b;
}

// faster version
// Ave time: (.707 + .571 + .581) / 3 = .620
int bitcount2(unsigned x){
	int b;

	for(;x != 0;++b)
		x &= (x-1);
	return b;
}
