#include <stdio.h>
#include <time.h>
#define MAX 2000000 
int binsearch(int x, int v[], int n); 
int binsearch2(int x, int v[], int n);

int main(){
	//build test data
	int test[MAX];
	int i, index;
	clock_t time_bin, time_bin2;
	
	for(i=0; i < MAX; ++i){
		test[i] = i;
	}
	for(i=0,time_bin=clock(); i <= MAX; ++i){
		if( i != (index=binsearch(i,test,MAX))){
			printf("element missing in binsearch\n");
		}
	}
	time_bin = clock() - time_bin;
	
	for(i=0,time_bin2=clock(); i <= MAX; ++i){
		if( i != (index=binsearch2(i,test,MAX))){
			printf("element missing in binsearch2\n");
		}
	}
	time_bin2 = clock() - time_bin2;
	printf("orig bs: %lu\nbs2: %lu\n",
		(unsigned long) time_bin, 
		(unsigned long) time_bin2
	);
}
/*
return index of matching value; if no match return -1 
modified to have 1 test inside the loop
*/
int binsearch2(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while(low <= high && x != v[mid]){
		if(x < v[mid]) {
			high = mid - 1;
		}else{ 
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	return x == v[mid] ? mid : -1;
}
/* 
return index of matching value; if no match return -1 
from page 58
*/
int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid]){
			high = mid - 1;
		}else if(x > v[mid]){
			low = mid + 1;
		}else{ // match found
			return mid;
		}
	}
	return -1; // no match
}
