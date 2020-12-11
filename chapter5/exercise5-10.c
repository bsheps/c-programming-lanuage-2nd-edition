#include <stdio.h>
#include <stdlib.h>	// for atof()
#include <string.h>
#include <ctype.h>

#define MAXOP	100 // max size of operand or operator
#define NUMBER	'0'

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void showInternals(int);

//reverse polish calculator
int main(int argc, char *argv[]){
	int type, len;
	double op2;
	char s[MAXOP], *str;

	while(--argc > 0) {
		showInternals(type);
		ungetch(' ');
		str = *++argv;
		len = strlen(str);
		while(--len >= 0)
			ungetch(*(str+len));
		type = getop(s);
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\tResult: %.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	printf("\tResult: %.8g\n", pop());
	return 0;
}

#define MAXVAL	100 // maximum depth of val stack

int sp = 0;			// next free stack position
double val[MAXVAL];	// value stack

// push push f onto value stack
void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void){
	if(sp > 0)
		return val[--sp];
	else {
		printf("pop error: stack empty.\n");
		return 0.0;
	}
}


// getop: get next operator or numeric operand
// separate inputs with either space or tab
int getop(char s[]){
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;	// ignore 
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	// not a number
	i = 0;
	if(isdigit(c))	// collect integer part
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')	// collect fractional part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if( c != EOF)
		ungetch(c);
	return NUMBER;
}

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

void showInternals(int type)
{
	int i;
	printf("Operation: %c\tstack:\t", type == NUMBER ? ' ' : type);
	for(i = 0; i < sp; i++)
		printf("%lf, ", val[i]);
	printf("\n\n");
}
