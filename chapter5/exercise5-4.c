#include <stdio.h>

int strend(char *, char *);

int main(){
	char *s = "Hello world!";
	char *t = "ld!";
	char *w = "worl";
	int t1 = strend(s,t);
	int t2 = strend(s,w);
	printf("(%s) end with (%s)? %s\n",s,t,t1? "true":"false");
	printf("(%s) end with (%s)? %s\n",s,w,t2? "true":"false");
	return 0;
}

/* s ends with t */
int strend(char *s, char *t){
	while(*s)
		s++;
	int i;
	for(i = 0; *t; t++, i++)
		;
	for(;(*s-- == *t--) && i >= 0; --i)
		;
	return i == -1 ? 1 : 0;
}
