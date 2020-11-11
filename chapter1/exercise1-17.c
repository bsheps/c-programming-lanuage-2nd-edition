#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main(){
	int len;
	char line[MAXLINE];

	while((len=getLine(line, MAXLINE)) > 0){
		if(len > 80){
			printf("len: %d\n%s\n", len, line);
		}
	}
	return 0;
}

int getLine(char s[], int lim){
	int c,d,i;
	for(i=0; (c=getchar()) != EOF && c != '\n'; ++i){
		if(i < lim-1){
			s[i] = c;
			d = c;
		}
	}
	if (d == '\n'){
		s[i]=d;
		++i;
	}
	s[i] = '\0';
	return i;
}

