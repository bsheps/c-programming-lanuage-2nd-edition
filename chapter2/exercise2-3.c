#include <stdio.h>
#include <math.h>
#define MAXLINE 1000

int htoi(char s[]);

int main(){
	char arr[MAXLINE];                                                      
        int c, i;                                                               
         
	for(i = 0;(i < MAXLINE-1) * ((c=getchar()) != EOF) * (c != '\n'); ++i){ 
                arr[i] = c;                                                     
        }                                                                       
        arr[i] = '\0';                                                          
        i = htoi(arr);
        printf("Hex input: %s, int output: %d\n", arr, i);      
}
/*
Possible test inputs and outputs:
0x1F = 31
0X1F = 31
1F   = 31
FFF  = 4096
junk = 0
*/
int htoi(char s[]){
	int i, n = 0;
	int power = 0;
	int len;
	int mod = 0; // modifier for optional 0x 0X start chars
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		mod = 2;
	}
	// how many hex chars are there
	for(len = mod; (s[len] >= '0' && s[len] <= '9') || 
			(s[len] >= 'a' && s[len] <= 'f') || 
			(s[len] >= 'A' && s[len] <= 'F');++len)
	{
		continue;
	}
	// setup for the 16^power
	power = len - mod - 1;
	// work left to right thru the hex
	for(i = mod; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n += (s[i] - '0')* pow(16,power--);	
		}else if(s[i] >= 'a' && s[i] <= 'f'){
			n += (10 + s[i] - 'a') * pow(16,power--);
		}else if(s[i] >= 'A' && s[i] <= 'F'){
			n += (10 + s[i] - 'A') * pow(16,power--);
		}
	}	
	return n;
}
