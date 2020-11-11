#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char line[], int len);

int main(){
	int len;
	char line[MAXLINE];

	while((len=getLine(line, MAXLINE)) != EOF){
		reverse(line, len);
		printf("%s\n", line);
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
	if(c == EOF){
		return EOF;
	}
	if (d == '\n'){
		s[i]=d;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char line[], int len){
	int i;
	char hold;
	for(i = 0; i < (len/2); ++i){
		hold = line[i];
		line[i] = line[len-i-1];
		line[len-i-1] = hold;
	}
}
