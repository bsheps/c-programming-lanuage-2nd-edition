#include <stdio.h>

int main(){
	int c;
	while((c = (getchar() != EOF)) == 1){
		printf("c is %d\n",c);
	}
	printf("c is %d\n", c);
}
