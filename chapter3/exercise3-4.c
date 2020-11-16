/*
In a 2s complement system, we find the value of out INT_MIN is 100...000
which for an 8bit system is 1000 0000 but we cannot represent -128 as a 
positive number in an 8 bit system because the left most bit is used for signing

So n = -n does not make -128 positive, it remains -128. Thus, we going thru the
loop it will exit immediately since n /= 10 will be negative (-128 / 10 = -12)
and 
> }while((n /= 10) > 0); evaluates to false.
*/

#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(){
	printf("Proof for why the largets negative number cannot be made positive:\n");
	printf("INT_MIN: %d, INT_MAX:%d\n",INT_MIN,INT_MAX);
	int n = INT_MIN;
	n = -n;
	printf("n = INT_MIN;\nn = -n;\nn: %d \\\\ still negative\n\n\n",n);
	
	int t1 = n;
	int t2 = INT_MAX;
	int t3 = -4234;
	char out[1000];
	itoa(t1, out);
	printf("int: %d\t\tchar: %s\n",t1, out);
	itoa(t2, out);
	printf("int: %d\t\tchar: %s\n",t2, out);
	itoa(t3, out);
	printf("int: %d\t\tchar: %s\n",t3, out);
	return 0;
}

void itoa(int n, char s[]){
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
}

void reverse(char s[]){
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
