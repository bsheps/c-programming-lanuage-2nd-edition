#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000

int getLine(char line[], int length);
int entab(char in[], char out[], int length);

int main(){
	char line[MAXLINE];
	char out[MAXLINE];
	int c;
	while((c=getLine(line, MAXLINE)) != EOF){
		c = entab(line, out, c);
		printf("%s", out);
		for(;c>=0;--c){
			out[c]='\0';
		}
	}
	return 0;
}

int entab(char in[], char out[], int len){
	int i=0,j; // 2 pointer for search, j will count spaces
	int index = 0; // index pointer for tracking out variable
	int col=1; // column counter; from 1 to TABSTOP 
	while(i<len){
		if(in[i] == ' '){
			j=i+1;
			++col;
			while(in[j]==' ' && col <= TABSTOP){
				++j;
				++col;
			}
			if(col > TABSTOP){ // insert tab and reset column count
				out[index++]='\t';
				col=1;
				i=j;
			}else{ // insert spaces
				for(;i != j; i++){
					out[index++]=' ';
				}
			}
		}else{
			++col;
			if(in[i] == '\t' || col > TABSTOP){
				col=1;
			}
			out[index++]= in[i++];
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

