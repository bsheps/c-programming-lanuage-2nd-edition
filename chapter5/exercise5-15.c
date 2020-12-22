#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int foldcmp(char *, char *);
int numcmp2(char *, char *);

int main(int argc, char *argv[]){
	int nlines, c;
	int rev = 0;
	int (*func)(void *, void *);
		func = &strcmp;
	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0]){
				switch(c){
				case 'n':
						func = numcmp2;
						break;
				case 'r':
						rev = 1;
						break;
				case 'f':
						func = foldcmp;
						break;
				default:
						printf("Error invalid arg: %c\n", c);
						return 2;
				}
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort2((void **) lineptr, 0, nlines-1,
			(int (*)(void*,void*))(func));
		printf("\n\n### sort ###\n\n");
		writelines(lineptr, nlines, rev);
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
		v2 = atof(s2);
		if(v1 < v2)
				return -1;
		else if(v1 > v2)
				return 1;
		else
				return 0;
}

int foldcmp(char *s1, char *s2){
		for(; tolower(*s1) == tolower(*s2) && *s1 != '\0'; ++s1, ++s2)
				;
		return tolower(*s1) - tolower(*s2);
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

void writelines(char *lineptr[], int nlines, int reverse){
	if(reverse)
			while(--nlines >= 0)
					printf("%s\n", *(lineptr+nlines));
	else
		while(nlines-- > 0)
				printf("%s\n", *lineptr++);
}

