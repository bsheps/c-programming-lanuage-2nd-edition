#include <stdio.h>
#include <stdlib.h>
#define TAB 4
#define MAXLINE 100

int getLine(char line[], int length);
int detab(char in[], char out[], int length);
void setTabs(int argc, char *argv[]);

static int *tabs;
static int startcol;
static int colspace;

int main(int argc, char *argv[]){
	char line[MAXLINE];
	char out[MAXLINE];
	int c;
	int cols;
	if(argc == 1){
		startcol = 0;
		colspace = TAB;
	}else if(argc == 3){
		char *start;
		while(--argc > 0){
			start = *++argv;
			if(*start == '-'){
				++start;
				startcol = atoi(start);
			}else if(*start == '+'){
				++start;
				colspace = atoi(start);
			}else{
				printf("invalid arguments. Must be detab -m -n\n");
				return -1;
			}
		}	
	}else{
		printf("invalid arguments. Must be detab -m -n\n");
		return -1;
	}
	cols = (MAXLINE - startcol) / colspace;
	int t[cols];
	tabs = t; 
	do{ 
		*tabs++ = startcol;
		startcol += colspace;
	}while(startcol < MAXLINE);
	*tabs = 0;
	tabs = t;
	// for debugging
/*	while(*tabs ){
		printf("%d ", *tabs);
		tabs++;
	}
*/
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
	int i, *tab;
	tab = tabs;
	int index = 0; // index is for out array
	for(i=0; i < len; ++i){
		if(in[i] == '\t'){
			out[index]= ' ';
			while(index >= *tab)
				++tab;
			++index;
			printf("tab: %d, index: %d\n",*tab, index);
			while(index < *tab)  // fill in rest of column
				out[index++] = ' ';
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

