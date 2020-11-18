#include <stdio.h>
#include <stdlib.h>	// for atof()
#include <math.h> // for remainder(x,y)
#include <ctype.h>
#include <string.h>

#define MAXOP	100 // max size of operand or operator
#define NUMBER	'0'
#define ADVANCED '1'
#define VARIABLE '2'

int getch(void);
void ungetch(int);
void advancedMath(char []);
int getop(char []);
void push(double);
double pop(void);
void peek(void);
void dup(void);
void swap(void);
void clear(void);
void showInternals(int);

/* reverse polish calculator
 4-6 had some help looking at solution manual; 
'5 A =' assigns 5 to A
'A 4 *' takes the value of A, pushes to stack making 5 4 * which equals 20
20 is stored in v where it can be used in the future aka:
v A / which pushes the value of v and A to make '20 5 /' and results in 4
*/
int main(){
	int i, type, prevType;
	double op2, v = 0;
	char s[MAXOP];
	double variables[26];

	for(i = 0; i < 26; i++){
		variables[i] = 0.0;
	}

	while((type = getop(s)) != EOF) {
		showInternals(type);
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
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push(remainder(pop(), op2));
			else
				printf("error: zero modulus\n");
			break;
		case ADVANCED:
			advancedMath(s);
			break;
		case '?':
			peek();
			break;
		case '~':
			swap();
			break;
		case '@':
			dup();
			break;
		case '!':
			clear();
			break;
		case '=':
			pop(); // remove pushed variable value
			if(prevType >= 'A' && prevType <= 'Z')
				variables[prevType - 'A'] = pop();
			else
				printf("variable assignment error: invalid var (A-Z only)");
			break;
		case '\n':
			v = pop();
			printf("\tResult: %.8g\n", v);
			break;
		default: 
			if(type >= 'A' && type <= 'Z'){
				push(variables[type - 'A']);
			}else if(type == 'v'){
				push(v);
			}else{
				printf("error: unknown command %s\n", s);
			}
			break;
		}
		prevType = type;
	}
	return 0;
}

// handle advanced math
void advancedMath(char s[]){
	double op2;
	if(!strcmp(s, "sin"))
		push(sin(pop()));
	else if(!strcmp(s, "exp"))
		push(exp(pop()));
	else if(!strcmp(s, "pow")){
		op2 = pop();
		push(pow(pop(), op2));
	}else
		printf("advancedMath error: %s no supported\n", s);
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

// print top element of stack, but don't pop it 
void peek(void){
	if(sp > 0)
		printf("Top of stack: %g\n",val[sp-1]);
	else
		printf("peek error: stack empty\n");
}

// duplicate top element of stack
void dup(void){
	if(sp > 0)
		push(val[sp-1]);
	else
		printf("dup error: stack empty.\n");
}

// swap top 2 elements of stack
void swap(void){
	if(sp > 1){
		double hold = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = hold;
	}else
		printf("swap error: stack has less than 2 entries.\n");
}

// clear stack
void clear(void){
	sp = 0;
}

// getop: get next operator or numeric operand
// separate inputs with either space or tab
int getop(char s[]){
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;	// ignore 
	s[1] = '\0';
	i = 0;
	if(isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if( c != EOF)
			ungetch(c);
		return i > 1 ? ADVANCED : s[0] + 0;		
	}
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	// not a number
	if(isdigit(c) || c == '-')	// collect integer part
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
