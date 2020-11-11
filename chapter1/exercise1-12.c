#include <stdio.h>

int main(){
	int c, isBetweenWords;
	while((c=getchar()) != EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			if(!isBetweenWords){
				putchar('\n');
				isBetweenWords = 1;
			}
		}else{
			putchar(c);
			isBetweenWords = 0;
		}
	}
	return 1;
}
