#include <stdio.h>

int lower(int c);

int main(){
	char arr[] = "HeLlO WoRlD";
	int i;
	for(i=0; arr[i] != '\0'; ++i)
		arr[i] = lower(arr[i] + 0); // plus 0 casts to int type
	printf("%s\n",arr);
	return 0;
}

int lower(int c){
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
