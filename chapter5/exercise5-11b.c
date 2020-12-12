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
	setTabs(argc, argv);
	while(--argc >= 0)
		printf("%d ", *tabs++);
	printf("setTab complete\n");
	while((c=getLine(line, MAXLINE)) != EOF){
		printf("getline complete: %d\n",c);
		c = detab(line, out, c);
		printf("detab complete\n");
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
	else{
		while(--argc >= 1)
			t[i++] = atoi(*++argv);
		t[i] = MAXLINE; // cannot exceed MAXLINE
	}
	tabs = t;
}

int detab(char in[], char out[], int len){
	int i;
	int index = 0; // index is for out array
	for(i=0; i < len; ++i){
		if(in[i] == '\t'){
			out[index]= ' ';
			while(index > *tabs)
				++tabs;
			++index;
			printf("tab: %d\n", *tabs);	
			while(index < *tabs)  // fill in rest of column
				out[index++] = ' ';
		}else{
			out[index] = in[i];
			++index;
		}
		printf("%d,%d\n", i, index);
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

