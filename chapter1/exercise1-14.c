#include <stdio.h>

int main(){
	int charCount[100], c, i, j;
	int SPACE_CHAR = 32;
	for(i=0; i<100; i++){
		charCount[i] = 0;
	}
	
	while((c=getchar()) != EOF){
		charCount[c - SPACE_CHAR]++;
	}
	printf("\nHistogram of char frequencies\n\n");
	for(i=0; i<100; i++){
		if(charCount[i] > 0){
			putchar(i+SPACE_CHAR);
			printf("\t|");
			for(j=0; j < charCount[i]; j++){
				printf("-");
			}
			printf("\n");
		}
	}
	return 1;
}
