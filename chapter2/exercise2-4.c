#include <stdio.h>

void squeeze2(char s1[], char s2[]);
int main(){
	char s1[] = "abcdef";
	char s2[] = "eca";
	squeeze2(s1,s2);
	printf("%s\n", s1);

	char s3[] = "eeee";
	char s4[] = "efg";
	squeeze2(s3,s4);
	printf("%s\n", s3);

	return 0;
}
/* delete each character in s1 that matches any character in s2 */
void squeeze2(char s1[], char s2[]){
	int i, j, k;
	for(i = 0; s2[i] != '\0'; ++i){
		k = 0;
		for(j = 0; s1[j] != '\0'; ++j){
			if(s1[j] != s2[i]){
				s1[k++] = s1[j];
			}
		}
		s1[k] = '\0';
	}
}
