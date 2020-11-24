#include <stdio.h>
#include <string.h>

void reverse(char s[], int l, int r);

int main(){
	char s[] = "!dlrow olleH";
	reverse(s,0,strlen(s)-1);
	printf("reversed: %s\n",s);
	return 0;
}

void reverse(char s[], int l, int r){
	if(l >= r)
		return;
	else{
		char tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;
		reverse(s, ++l, --r);
	}
}
