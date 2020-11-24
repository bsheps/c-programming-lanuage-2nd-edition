#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int getLine2(char out[], int lim); 

int main(){
	printf("in: %d\n",isalpha('-'));
	return 0;
}

// getline: get line into s, return length                                         
int getLine2(char out[], int lim){                                                 
    int c, i;                                                                      
                                                                                   
    i = 0;                                                                         
    while (--lim > 0 && ( c = getchar()) != EOF && c != '\n')                      
        out[i++] = c;                                                              
    if(c == '\n')                                                                  
        out[i++] = c;                                                              
    out[i] = '\0';                                                                 
    return i;                                                                      
} 
