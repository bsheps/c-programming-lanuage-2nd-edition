#include <stdio.h>
#include <stdlib.h>
#define TABSTOP 8
#define MAXLINE 100

int getLine(char line[], int length);
int entab(char in[], char out[], int length);
void setTabs(int argc, char *argv[]);

static int *tabs;
/* Entab - replace excess spaces with tab
The program is somewhat awkward with the parameters because the outcome is the
same as without due to my computer forcing tabs to be 8 characters long. Does
not appear to be a good way to override this setting.
*/
int main(int argc, char *argv[]){
	char line[MAXLINE];
	char out[MAXLINE];
	int c, cols;
	//setTabs(argc, argv);
	if(argc == 1)
		cols = (MAXLINE / 8) + 1;
	else
		cols = argc;
	int t[cols];
	tabs = t;
	if(argc == 1)
		for(argc = 8; argc < MAXLINE; argc +=8)
			*tabs++ = argc;
	else
		while(--argc >= 1)
			*tabs++ = atoi(*++argv);
	*tabs = 0;
	tabs = t;
	 // for debugging
/*	while(*tabs ){
		printf("%d ", *tabs);
		tabs++;
	}
*/
	while((c=getLine(line, MAXLINE)) != EOF){
		c = entab(line, out, c);
		printf("%s", out);
		for(;c>=0;--c){
			out[c]='\0';
		}
	}
	return 0;
}

void setTabs(int argc, char *argv[]){
	int t[argc], i = 0;
	if(argc == 1)
		for(argc = 8; argc < MAXLINE; argc +=8)
			t[i++] = argc;
	else
		while(--argc >= 1)
			t[i++] = atoi(*++argv);
	tabs = t;
}

int entab(char in[], char out[], int len){
	int i=0,j; // 2 pointer for search, j will count spaces
	int index = 0; // index pointer for tracking out variable
	int col=1; // column counter; from 1 to TABSTOP 
	while(i<len){
		if(in[i] == ' '){
			j=i+1;
			++col;
			while(in[j]==' ' && col <= *tabs && col <= TABSTOP){
				++j;
				++col;
			}
			if(col > *tabs || col > TABSTOP){ // insert tab and reset column count
				out[index++]='\t';
				++tabs;
				col=1;
				i=j;
			}else{ // insert spaces
				for(;i != j; i++){
					out[index++]=' ';
				}
			}
		}else{
			++col;
			if(in[i] == '\t' || col > *tabs){
				col=1;
				++tabs;
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

