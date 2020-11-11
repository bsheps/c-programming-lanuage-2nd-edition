#include <stdio.h>

int main(){
	int c;
	int blank = 0;
	int tab = 0;
	int newline = 0;

	while((c=getchar()) != EOF){
		if(c == ' ')
			blank++;
		else if(c == '\t')
			tab++;
		else if(c == '\n')
			newline++;
	}
	printf("blank: %d\ntab: %d\nnewline: %d\n",blank,tab,newline);
}
