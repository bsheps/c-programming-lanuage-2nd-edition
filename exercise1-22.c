#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000
#define LINELENGTH 64

int getLine(char line[], int length);
int entab(char in[], char out[], int length);
void clearArray(char arr[], int len);
void foldLine(char in[], int length);

int main(){
	char line[MAXLINE];
	char out[MAXLINE];
	int c;
	while((c=getLine(line, MAXLINE)) != EOF){
		foldLine(line, c);
		printf("%s", line);
	}
	return 0;
}

/* I plan to replace the last blank in the line with a newline char.
 * If a blank does not exist, then I will insert a newline
 */ 
void foldLine(char in[], int len){
	int lineLength = 1;
	int blank = -1;
	int i;
	for(i = 0; i < len; ++i){
		if(in[i] == ' '){
			blank = i;
			++lineLength;
		}else if(in[i] == '\t'){
			blank = i;
			++lineLength;
			lineLength += TABSTOP - (lineLength % TABSTOP);
		}else{
			++lineLength;
		}

		if(lineLength >= LINELENGTH){
			if(blank != -1){ // replace most recent blank
				in[blank] = '\n';
			}else{ // no tabs or spaces found
				int j;
				for(j = len; j > i; --j){
					in[j] = in[j-1];
				}
				in[i] = '\n';
				++len;
				in[len] = '\0';
			}
			blank = -1;
			lineLength = 1;
		}
	}
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
