#include <stdio.h>
#include <stdlib.h>
#define TAB 4
#define MAXLINE 100

int getLine(char line[], int length);
int detab(char in[], char out[], int length);
void setTabs(int argc, char *argv[]);

static int *tabs;

int main(int argc, char *argv[]){
	char line[MAXLINE];
	char out[MAXLINE];
	int c;
	int cols;
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
	/* // for debugging
	while(*tabs ){
		printf("%d ", *tabs);
		tabs++;
	}*/
	printf("setTab complete\n");
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
			while(index > *tab)
				++tab;
			++index;
			printf("tab: %d\n", *tab);	
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

