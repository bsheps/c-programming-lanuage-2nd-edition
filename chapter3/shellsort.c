#include <stdio.h>

void shellsort(int v[], int n);
void printArr(int a[], int n, int gap, int i, int j);

int main(){
	int test[] = {17,32,54,25,12,64,93,2,67,4};
	printf("----------------------------\t\tgap\ti\tj\n");
	shellsort(test,10);	
}

void shellsort(int v[], int n){
	int gap, i, j, temp;
	printArr(v,n,-1,-1,-1);	
	for(gap = n/2; gap > 0; gap /= 2){
		for(i = gap; i < n; i++){
			for(j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
				printArr(v,n,gap,i,j);
			}
		}
	}
}

void printArr(int a[], int n, int gap, int i, int j){
	int it=0;
	while(it < n){
		printf("%d%s", a[it], it == n-1 ? "\t\t" : a[it] < 10 ? " ," : ",");
		it++;
	}
	printf("%d\t%d\t%d\n",gap,i,j);
}
