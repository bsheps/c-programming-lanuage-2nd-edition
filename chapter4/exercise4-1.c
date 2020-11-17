#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main(){
	int n;
	char s1[] = "abcd";
	char t1[] = "bc";
	printf("Test 1:  %d\n", strrindex(s1,t1));
	char s2[] = "abcd";
	char t2[] = "d";
	printf("Test 2  %d\n", strrindex(s2,t2));
	char s3[] = "abcd";
	char t3[] = "a";
	printf("Test 3  %d\n", strrindex(s3,t3));
	char s4[] = "abcd";
	char t4[] = "e";
	printf("Test 4  %d\n", strrindex(s4,t4));
	return 0;
}

/* returns the rightmost occurrence of t in s, or -1 if none */
int strrindex(char s[], char t[]){
	int i, j;
	int lenS = strlen(s);
	int lenT = strlen(t);
	for(i = lenS - lenT; i >= 0; --i){
		for(j = 0; 	s[i+j] == t[j] && j < lenT; j++)
			continue;
		if(j == lenT)
			return i;	
	}
	return -1;
}
