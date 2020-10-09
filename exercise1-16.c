#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0;
	while((len=getLine(line, MAXLINE)) > 0){
		if(len > max){
			max=len;
			copy(longest, line);
		}
	}
	if(max > 0){
		printf("Max is: %d\n%s", max, longest);
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

void copy(char to[], char from []){
	int i;
	i=0;
	while((to[i] = from[i]) != '\0')
		++i;
}
