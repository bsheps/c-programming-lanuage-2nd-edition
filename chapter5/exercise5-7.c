#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	// max number of lines
char *lineptr[MAXLINES];		// pointer to text lines

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(){
	int nlines;			// number of lines read

	if((nlines = readlines(lineptr,MAXLINES)) >= 0){
		qsort(lineptr, 0, nlines-1);
		printf("--------------------\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("Error: Too many lines read\n");
		return -1;
	}
}

#define MAXLEN 1000
int ggetline(char *, int);
char *alloc(int);


int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = ggetline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';	// replace new line with endline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right){
	int i, last;
	void swap(char *v[], int i, int j);

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left +1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

#define ALLOCSIZE 10000		// storage for alloc

static char allocbuf[ALLOCSIZE];	// storage for alloc
static char *allocp = allocbuf;		// next free position

char *alloc(int n){
	if (allocbuf + ALLOCSIZE - allocp >= n){		// n will fit
		allocp += n;
		return allocp - n; // old pointer
	} else {
		return 0;
	}
}

int ggetline(char s[], int lim){
	int c, i;

	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void swap(char *v[], int i, int j){
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

