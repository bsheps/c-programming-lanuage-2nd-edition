#include <stdio.h>

int any(char s1[], char s2[]);

int main(){
	char t1[] = "hello";
	char t2[] = "abcdo";
	printf("%d\n",any(t1,t2));

	char t3[] = "nothing";
	char t4[] = "abcdef";
	printf("%d\n", any(t3,t4));

	return 0;
}

/* returns first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[]){
	int i, j;
	for(i = 0; s1[i] != '\0';++i){
		for(j=0; s2[j] != '\0'; ++j){
			if(s1[i] == s2[j]){
				return i;
			}
		}
	}
	return -1;
}
