#include <stdio.h>

void hlSwap(int i, int j);
void qsort(int v[], int left, int right);
void printArr(int v[]);

int main(){
	int test[10] = {2,5,8,3,4,1,9,10,7,6};

	qsort(test, 0, 9);

	printf("Done.\n ");
	printArr(test);

	return 0;
}


void qsort(int v[], int left, int right){
	printf("enter qsort, left: %d, right %d, ",left,right);
	printArr(v);
	int i, last;
	void swap(int v[], int i, int j);

	if(left >= right) // less than 2 elem, do nothing
		return;
	swap(v, left, (left + right)/2); // move partition elem
	last = left;
	for( i = left+1; i <= right; i++)
		if(v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int v[], int i, int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	printf("Swap( %d, %d) - indices: %d, %d\n", v[i], v[j],i, j);
	hlSwap(i, j);
	printArr(v);
}

void printArr(int v[]){
	int i;
	printf("Array: ");
	for(i = 0; i < 10; i++)
		printf("%d,",v[i]);
	printf("\n");
}

void hlSwap(int k, int j){
	if(k == j)
		return;
	int i;
	printf("       ");
	for(i = 0; i < 10; i++){
		if(i == k || i == j)
			printf("S ");
		else
			printf("  ");
	}
	printf("\n");
}

