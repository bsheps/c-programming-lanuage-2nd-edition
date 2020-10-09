#include <stdio.h>

int fahrToCelsius(int fahr);

int main(){
	int fahr;
	int lower, upper, step;

	lower=0;
	upper=300;
	step=20;

	fahr=lower;
	while(fahr <= upper){
		printf("%d\t%d\n", fahr, fahrToCelsius(fahr));
		fahr = fahr + step;
	}
	return 1;
}

int fahrToCelsius(int fahr){
	return 5 * (fahr-32) / 9;
}
