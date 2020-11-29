#include <stdio.h>

char *stringncpy(char *s, char *t, int n);
char *stringncat(char *s, char *t, int n);
int stringncmp(char *s, char *t, int n);

int main(){

	return 0;
}

/*	copy at most n chars of string t to s. return s.
*	pad with '\0's if t has fewer than n characters.
*/
char *stringncpy(char *s, char *t, int n){

}

/*	concatenate at most n charactesr of string t to string s,
*	terminate s with '\0' and return s;	
*/
char *stringncat(char *s, char *t, int n){

}

/*	compare at most n characters of string s to string t;
*	return  <0 if s<t, 0 if s == t, >0 if s<t
*/
int stringncmp(char *s, char *t, int n){

}
