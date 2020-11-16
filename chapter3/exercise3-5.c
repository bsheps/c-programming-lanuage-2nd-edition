#include <string.h>
#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){
	char out[1000];
	int t1 = 974;
	itob(t1, out, 16);
	printf("int: %d   base: %d   out:%s\n",t1,16,out);
	itob(t1, out, 8);
	printf("int: %d   base: %d   out:%s\n",t1,8,out);
	itob(t1, out, 2);
	printf("int: %d   base: %d   out:%s\n",t1,2,out);
	return 0;
}
/* integer to base
n: integer in
b: base to convert to
s: string output of new base number
*/
void itob(int n, char s[], int b){
	int i = 0;
	int c;
	do {
		c = n % b;
		s[i++] = c < 10 ? c + '0' : c - 10 + 'A'; 
	}while(n /= b);
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
