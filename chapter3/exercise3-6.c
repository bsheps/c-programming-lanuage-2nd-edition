#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(){
	int t1 = INT_MIN;
	int t2 = INT_MAX;
	int t3 = -4234;
	int t4 = 1;
	char out[1000];
	itoa(t1, out, 8);
	printf("int: %d\nwidth:%d\n%s\n\n",t1,8,out);
	itoa(t2, out, 8);
	printf("int: %d\nwidth:%d\n%s\n\n",t2,8,out);
	itoa(t3, out, 8);
	printf("int: %d\nwidth:%d\n%s\n\n",t3,8,out);
	itoa(t4, out, 8);
	printf("int: %d\nwidth:%d\n%s\n\n",t4,8,out);
	return 0;
}
/*
integer to ascii
n: integer in
s: output ascii string
w: min width of string
*/
void itoa(int n, char s[], int w){
	int i, sign, rem;
	sign = n;
	i=0;
	do {
		rem = n % 10;
		s[i++] = rem < 0 ? (-rem) + '0' : rem + '0';
	}while(n /= 10);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	if(i < w){
		int pad = w - i;
		char temp[i];
		int k;
		// copy s into temp
		for(k = 0; k < i;k++){
			temp[k] = s[k];
		}
		temp[k] = '\0';
		// pad s
		for(i = 0; i < pad; i++){
			s[i] = ' ';
		}
		// replace temp into s
		for(k = 0;i < w; i++, k++){
			s[i] = temp[k];
		}
		s[i] = '\0';
	}
}

void reverse(char s[]){
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
