#include <stdio.h>
#define TAB 4
#define MAXLINE 1000

int getLine(char line[], int length);
int detab(char in[], char out[], int length);

int main(){
	char line[MAXLINE];
	char out[MAXLINE];
	int c;
	while((c=getLine(line, MAXLINE)) != EOF){
		c = detab(line, out, c);
		printf("%s", out);
		for(;c>=0;--c){
			out[c]='\0';
		}
	}
	return 0;
}

int detab(char in[], char out[], int len){
	int i;
	int index = 0; // index is for out array
	for(i=0; i < len; ++i){
		if(in[i] == '\t'){
			out[index]= ' ';
			++index;
			while(index % TAB !=0){  // fill in rest of column
				out[index] = ' ';
				++index;
			}
		}else{
			out[index] = in[i];
			++index;
		}
	}
	return index;
}

int getLine(char line[], int len){
	int c, i;
	for(i=0; i < len-1 && (c=getchar()) != EOF && c != '\n'; ++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i]='\0';
	return i;
}

