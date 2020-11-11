#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int length);
void removeComments(char in[], char out[], int len);
void clearArray(char arr[], int len);
int isBalanced(char line[], int len);

int main(){
	char line[MAXLINE];
	char out[MAXLINE];
	int c;
	while((c=getLine(line, MAXLINE)) != EOF){
		removeComments(line, out, c);
		if(isBalanced(out,c)){
			printf("true\n");
		}else{
			printf("false\n");
		}	
		clearArray(out, MAXLINE);
	}
	return 0;
}
/*
check for unbalance brackets, braces and parenthesis. Don't forget about quotes
and comments.

My thoughts are to start by removing the comments with the program from 
exercise 23. Next, using a char array and a pointer as a stack, I will push a
corresponding charr on for each opening bracket, brace, parenthesis, double or 
single quote. Then as I come across a closing bracket, brace, parenthesis,
double or single quote; I will check the top of the stack and pop it off if 
matching. Otherwise, return false. If at end of file the stack is not empty,
return false.
*/

int isBalanced(char line[], int len){
	char stack[MAXLINE];
	int ptr = 0;
	int i;
	int singleQuote = 0;
	int doubleQuote = 0;
	for(i = 0; i < len; ++i){
		if(!singleQuote && !doubleQuote){
			switch(line[i]){
				case '(' :
					stack[ptr++] = ')';
					break;
				case ')' :
					if(ptr < 1 || stack[ptr -1] != ')'){
						return 0;
					}
					--ptr;
					break;
				case '[' : 
					stack[ptr++] = ']';
					break;
				case ']' :
					if(ptr < 1 || stack[ptr-1] != ']'){
						return 0;
					}
					--ptr;
					break;
				case '{' :
					stack[ptr++] = '}';
					break;
				case '}' :
					if(ptr < 1 || stack[ptr-1] != '}'){
						return 0;
					}
					--ptr;
					break;
				case '\'' :
					singleQuote = 1;
					break;
				case '\"' :
					doubleQuote = 1;
					break;
				default:
					// do nothing
					break;		
			}
		}else if(singleQuote && line[i] == '\''){
			singleQuote = 0;
		}else if(doubleQuote && line[i] == '\"'){
			doubleQuote = 0;
		}
	}
	return ptr == 0 && !singleQuote && !doubleQuote;
}

/* 
There are two types of comments: /* type which comment out everything inbetween
and // which comments out everything until the new line character. 

edge case: if either are used inbetween quotations. ie: printf("// /*")

possible approaches: 2 pointer method - when a quote is found, stop the slow
ptr and move fast pointer til end is found, then shift everything to the right
of the fast ptr. Maybe not the fastest, but doesn't require extra space

other approach that can be done in 1 pass: iterate thru char array, adding each
item to a second array while omitting comments. O(n) time, O(n) space.
 */

void removeComments(char in[], char out[], int len){
	int i, j = 0;
	int singleQuote = 0;
	int doubleQuote = 0;
	for(i = 0; i < len - 1; ++i){
		char cur = in[i];
		char next = in[i + 1];
		if(!singleQuote && !doubleQuote && cur  == '/' && next == '/'){
			while(in[i] != '\n' && i < len){
				++i;
			}
			out[j++] = '\n';
		}else if(!singleQuote && !doubleQuote && cur == '/' && next == '*'){
			i = i +2;
			while(i < len -1 && !(in[i] == '*' && in[i+1] == '/')){
				++i;
			}
			if(i < len - 1 && in[i] == '*' && in[i+1] == '/'){
				++i; // move over the / so we omit it
			}
		}else {
			if(singleQuote && cur == '\''){
				singleQuote = 0;
			}else if(!doubleQuote && cur == '\''){
				singleQuote = 1;
			}
			if(doubleQuote && cur == '\"'){
				doubleQuote = 0;
			}else if(!singleQuote && cur == '\"'){
				doubleQuote = 1;
			}
			out[j++] = cur;
		}
	}
	if(i == len -1){
		out[j++] = in[i];
	}
	out[j] = '\0';
}

int getLine(char line[], int len){
	int c, i;
	for(i=0; i < len-1 && (c=getchar()) != EOF && c != '\n'; ++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i++]='\0';
	return i;
}

void clearArray(char arr[], int len){
	int i;
	for(i = 0; i < len; ++i){
		arr[i] = '\0';
	}
}
