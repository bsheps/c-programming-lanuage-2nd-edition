#include <stdio.h>
#define MAXLINE 1000

int main(){
	char arr[MAXLINE];
	int c, i;
	/* if any evaluate to false (aka 0) then zero multiplied by anything
	   is zero (aka false)
	*/
	for(i = 0;(i < MAXLINE-1) * ((c=getchar()) != EOF) * (c != '\n'); ++i){
		arr[i] = c;
	}
	if(c == '\n'){
		arr[i++] = c;
	}
	arr[i] = '\0';
	printf("%s", arr);
	return 0;
}
