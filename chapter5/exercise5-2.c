#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
int getint(int *);
int getfloat(float *);

int main(){
	int c;
	float n = 0.0;
	while((c = getfloat(&n)) != EOF)
		if(c > 0)
			printf("input: %f\n", n);
	return 0;
}

/* getint: get next float from input into *pn */
int getfloat(float *pn)
{
	int c, i, sign;
	
	while (isspace(c = getch())) // skip whitespaces
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();
	if(!isdigit(c)){
		ungetch(c);
		return 0;
	}
	for(*pn = 0.0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if(c == '.')
		c = getch();
	for(i = 1; isdigit(c); c = getch(), i *= 10)
		*pn = 10 * *pn + (c - '0');
	if(c != EOF)
		ungetch(c);
	*pn = *pn / i * sign;
	return c;
}


/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;
	
	while (isspace(c = getch())) // skip whitespaces
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();
	if(!isdigit(c)){
		ungetch(c);
		return 0;
	}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

// copied from exercise4-10.c
#define BUFSIZE	100

char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf

int getch(void){	// get a (possibly pushed back) character
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){	// push character back on input
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
