#include <stdio.h>

int printd(int n, char s[], int i);

int main(){
	char s[10];
	int n = -2431;
	printd(n,s,0);
	printf("s: %s\n", s);
	return 0;
}

int printd(int n, char s[], int i){
	if(n < 0){
		s[i++] = '-';
		n *= -1;
	}
	if(n / 10){
		i = printd(n/10, s, i);
	}
	s[i++] = (n % 10) + '0';
	s[i] = '\0';
	return i;
}
