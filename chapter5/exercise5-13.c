#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
static int tail;

int getline2(char *, int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
char *alloc(int);

int main(int argc, char *argv[]){
	int nlines;

	if(argc == 1){
		tail = 10;
	}else if(argc == 2 && (*++argv)[0] == '-'){
		tail = atoi(argv[0] + 1);
	}else{
		printf("error: invalid parameters\n tail -[num input lines]\n");
		return 2;	
	}

	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("error: input too big\n");
		return 1;
	}
}

#define MAXLEN 1000 // max length for input lines

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while((len = getline2(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len-1] = '\0'; // delete new line
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

int getline2(char *s, int lim){
	int c;
	char *p;
	p = s;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if(c == '\n')
		*p++ = c;
	*p = '\0';
	return p - s;
}

#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if(allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp -n; // old p
	}else // no room
		return 0;
}

void writelines(char *lineptr[], int nlines){
	if(tail > nlines){
		while(nlines-- > 0)
			printf("%s\n", *lineptr++);
	}else{
		for(lineptr += nlines ; tail > 0; --tail)
			printf("%s\n", *(lineptr - tail));
	}
}

