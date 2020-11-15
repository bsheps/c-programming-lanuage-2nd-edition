#include <stdio.h>

void expand(char s1[], char s2[]);

int main(){
	char out[200];
	char t1[] = "a-z";
	char t2[] = "a-z0-9";
	char t3[] = "a-b-c";
	char t4[] = "-a-z";
	char t5[] = "-a-z-";
	char t6[] = "-0-z-";
	expand(t1,out);
	printf("short: %s\nexpand: %s\n\n",t1,out);
	expand(t2,out);
	printf("short: %s\nexpand: %s\n\n",t2,out);
	expand(t3,out);
	printf("short: %s\nexpand: %s\n\n",t3,out);
	expand(t4,out);
	printf("short: %s\nexpand: %s\n\n",t4,out);
	expand(t5,out);
	printf("short: %s\nexpand: %s\n\n",t5,out);
	expand(t6,out);
	printf("short: %s\nexpand: %s\n\n",t6,out);
	return 0;
}

/*Expands shorthand notations like a-z into abc...xyz
handles cases: a-b-c, a-z0-9 and -a-z
*/
void expand(char s1[], char s2[]){
	int min = 0;
	int i, j = 0;
	for(i = 0; s1[i] != '\0'; ++i){
		if(s1[i] == '-' && (i == 0 || s1[i+1] == '\0')){
			s2[j++] = '-';
			++i;
		}else if(s1[i] == '-'){
			for(min = s1[i-1]; min <= s1[i+1]; ++min){
				if(j>0 && s2[j-1] == min)
					continue;
				s2[j++] = min;
			}
			++i;
		}
	}	
	s2[j] = '\0';
}
