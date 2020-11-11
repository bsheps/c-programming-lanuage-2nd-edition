#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
int rmTrailBlanks(char line[], int length);

int main(){
	int len;
	char line[MAXLINE];

	while((len=getLine(line, MAXLINE)) != EOF){
		if(rmTrailBlanks(line,len) > 0){
			printf("%s\n", line);
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
	if(c == EOF){
		i = EOF;
	}
	return i;
}

int rmTrailBlanks(char line[], int len){
	if(line[len] == '\0')
		--len;
	if(line[len] == '\n')
		--len;
	while(len >=0 && (line[len] == '\t' || line[len] == ' ')){
		--len;// find position where first non tab or space char is	
	}
	if(len >= 0 && line[len] != '\n')
		line[++len] = '\0';
	return len;
}
