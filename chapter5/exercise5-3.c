#include <stdio.h>

void stringcat(char *s, char *t);

int main(){
	char s[20] = "hello, ";
	char t[20] = "world!";	
	stringcat(s,t);
	printf("%s\n", s);
	return 0;
}

void stringcat(char *s, char *t){
	while(*s)
		s++;
	while(*s++ = *t++)
		;	
}
