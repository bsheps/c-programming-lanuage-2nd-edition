#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp2(char *, char *);

int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0;	// 1 if numeric sort

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort2((void **) lineptr, 0, nlines-1,
			(int (*)(void*,void*))(numeric ? numcmp2 : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("input too big to sort\n");
		return 1;
	}
}

// sort v[left] ... v[right] into increasing order
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *)){
		int i, last;
		void swap(void *v[], int, int);

		if(left >= right)
				return;
		swap(v, left, (left + right)/2);
		last = left;
		for(i = left+1; i <= right; i++)
				if((*comp)(v[i], v[left]) < 0)
						swap(v, ++last, i);
		swap(v, left, last);
		qsort2(v, left, last-1, comp);
		qsort2(v, last+1, right, comp);
}

int numcmp2(char *s1, char *s2){
		double v1, v2;

		v1 = atof(s1);
		v1 = atof(s2);
		if(v1 < v2)
				return -1;
		else if(v1 > v2)
				return 1;
		else
				return 0;
}

void swap(void *v[], int i, int j){
		void *temp;
		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
}

#define MAXLEN 1000 // max length for input lines
int getline2(char *s, int lim);
char *alloc(int n);

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
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

