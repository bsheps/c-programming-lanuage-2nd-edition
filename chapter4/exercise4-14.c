#include "stdio.h"

#define swap(t,x,y) { \
t temp; \
temp = x; \
x = y; \
y = temp; \
}

int main(){
	int x = 43;
	int y = 4;
	printf("x : %d, y : %d\n", x , y );

	swap(int, x, y);
	printf("swapped\nx : %d, y : %d\n", x , y );
	return 0;
}
