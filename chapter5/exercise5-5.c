#include <stdio.h>
#include <string.h>

void stringncpy(char *s, char *t, int n);
void stringncat(char *s, char *t, int n);
int stringncmp(char *s, char *t, int n);

int main(){
	char s1[20] = "bbbbbbbb";
	char s2[20] = "bbbbbbbb";
	char t[20] = "world";
	stringncpy(s1,t,3);
	strncpy(s2,t,3);
	printf("strncpy test1: %s, expected: %s\n", s1, s2);
	stringncpy(s1,t,5);
	strncpy(s2,t,5);
	printf("strncpy test2: %s, expected: %s\n", s1, s2);
	stringncpy(s1,t,7);
	strncpy(s2,t,7);
	printf("strncpy test3: %s, expected: %s\n", s1, s2);
	char s3[20] = "bbbbbbbb";
	char s4[20] = "bbbbbbbb";

	stringncat(s3,t,3);
	strncat(s4,t,3);
	printf("\nstrncat test1: %s, expected: %s\n", s3, s4);
	stringncat(s3,t,5);
	strncat(s4,t,5);
	printf("strncat test2: %s, expected: %s\n", s3, s4);
	stringncat(s3,t,7);
	strncat(s4,t,7);
	printf("strncat test3: %s, expected: %s\n", s3, s4);
	
	char s5[20] = "helloWorld";
	char t1[20] = "hellofriend";
	printf("\nstrncmp test2: %d, expected: %d\n", stringncmp(s5,t1,5), strncmp(s5,t1,5));
	printf("strncmp test3: %d, expected: %d\n", stringncmp(s5,t1,8), strncmp(s5,t1,8));
	printf("strncmp test4: %d, expected: %d\n", stringncmp(t1,s5,8), strncmp(t1,s5,8));
	
	return 0;
}

/*	copy at most n chars of string t to s. return s.
*	pad with '\0's if t has fewer than n characters.
*/
void stringncpy(char *s, char *t, int n){
	for(;n > 0 && (*s++ = *t++);n--)
		;
	for(--n;n > 0;n--)
		*s++ = '\0';
}

/*	concatenate at most n characters of string t to string s,
*	terminate s with '\0' and return s;	
*/
void stringncat(char *s, char *t, int n){
	void stringncpy(char *, char *, int);
	while(*s)
		*s++;
	stringncpy(s, t, n);
	/*for(; n > 0 && (*s++ = *t++); --n)
		;
	*s = '\0';	
*/
}

/*	compare at most n characters of string s to string t;
*	return  <0 if s<t, 0 if s == t, >0 if s<t
*/
int stringncmp(char *s, char *t, int n){
	for(--n; n > 0 && *s == *t; --n, ++s, ++t)
		;
	return *s - *t;
}
