#include <stdio.h>
#include <ctype.h>

int ggetline(char *, int);
int atoi(char *);
void *itoa(int, char *);
void reverse(char *);
int strindex(char *s, char *t);
int getop(char *);

int main(){
	char s[10];
	int n;
	/*
	// testing for ggetline
	printf("test getline (ctrl+d to exit)\n");
	while(ggetline(s,10) > 0){
		printf("ggetline: %s",s);
	}
	
	// testing for atoi
	printf("test atoi, enter integers. (ctrl+d to exit)\n");
	while(ggetline(s,10) > 0){
		n = atoi(s);
		printf("atoi: %d\n", n);
	}
	
	// testing for reverse
	char z[] = "hello world!";
	reverse(z);
	printf("%s\n",z);
	
	int t1 = 12345, t2 = -1234, t3 = 0;
	char c[20];
	itoa(t1,c);
	printf("itoa %s\n", c);
	itoa(t2,c);
	printf("itoa %s\n", c);
	itoa(t3,c);
	printf("itoa %s\n", c);
	
	// test strindex
	char v[] = "abcdefghijklmnop";
	char y1[] = "fghik";
	printf("strindex(%s,%s)=%d\n",v,y1,strindex(v,y1));
	*/
	// test getop (recall it is for reverse polish notation calculator
	while((n = getop(s)) != EOF)
		printf("getop: %d, %s\n", n, s);
	return 0;
}

int ggetline(char *s, int lim){
	char c, *p = s;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s = '\0';	
	return s - p;
}

int atoi(char *s){
	int n, sign = 1;
	if(*s == '-'){
		sign = -1;
		++s;
	}
	for(n=0; *s && *s != '\n'; s++)
		n = n * 10 + (*s - '0');
	return n * sign;
}

void *itoa(int n, char *s){
	int sign = 1;
	char *p = s;
	if(n < 0){
		sign = -1;
		n *= -1;
	}
	do{
		*s++ = (n % 10) + '0';
	}while(n /= 10);
	if(sign == -1)
		*s++ = '-';
	*s = '\0';
	reverse(p);
}

void reverse(char *s){
	char *r = s;
	while(*(r + 1)) // move r to last element
		r++;
	while(r > s){
		char t = *s;
		*s++ = *r;
		*r-- = t;
	}
}

/* return index of t in s, -1 if none */
int strindex(char *s, char *t){
	char *p = s;
	char *i, *j;
	for(; *s != '\0'; ++s){
		for(i = s, j = t; *i == *j && *j != '\0'; i++, j++)
			printf("%s\t%s\n",i,j);
		if(*j == '\0' && j > t)
			return s - p;
		
	}
	return -1;
}

/* get next operator or numeric operand */
int getop(char *s){
	int c;
	static int holder = 0; // 0 represents no char
	while((*s = c = (holder == 0 ? getchar() : holder)) == ' ' || c == '\t'){
		holder = 0;	
		// ignore 
	}
	*(s+1) = '\0';
	if (!isdigit(c) && c != '.')
		return c;	// not a number
	if(isdigit(c))	// collect integer part
		while(isdigit(*++s = c = getchar()))
			;
	if(c == '.')	// collect fractional part
		while (isdigit(*++s = c = getchar()))
			;
	*s = '\0';
	if( c != EOF)
		holder = c;
	return '0';
}

