#include <stdio.h>

int main(){
	int wc[28], i, j, c;
	for(i=0; i < 28; i++){
		wc[i]=0;
	}
	i = 0;
	while((c=getchar()) != EOF){
		if((c >= 'A' && c<= 'Z') || (c >= 'a' && c <= 'z')){
			i++;
		}else{
			wc[i]++;
			i=0;
		}
	}
	//edge case where a word ends with EOF
	if(i != 0){
		wc[i]++;
	}
	printf("\nHistogram of the frequency of various word lengths\n\n");
	for(i = 1; i < 28; i++){
		if(wc[i] > 0){
			printf("%d\t|", i);
			for(j=0; j < wc[i]; j++){
				printf("-");
			}
			printf("\n");
		}
	}
	return 1;
}
