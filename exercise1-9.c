#include <stdio.h>

int main(){
	int isLeadBlank = 0;
	int c;
	while((c=getchar()) != EOF){
		if(c == ' ' && isLeadBlank){
			//do nothing
		}else{
			isLeadBlank = (c == ' ');
			putchar(c);
		}
	}
}
