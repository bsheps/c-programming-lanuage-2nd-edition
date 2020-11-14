#include <stdio.h>

void escape(char t[], char s[]);
void convEscapes(char t[], char s[]);
int main(){
	char testIn[] = "Hello\nWorld\tHow\tDoes\tit\tfeel\t";
	char testOut[50];
	char testOut2[50];
	printf("Test data:\n%s\n\n",testIn);
	escape(testIn, testOut);
	printf("Escape test:\n%s\n\n",testOut);
	convEscapes(testOut, testOut2);
	printf("convEscapes test:\n%s\n",testOut2);
	return 0;	
}

/* convert tab and newline to visible escape sequences
t is the input, s is the output
*/
void escape(char t[], char s[]){
	int i = 0;
	int j = 0;
	while(t[i] != '\0'){
		switch(t[i]){
		case '\n':
			s[j++]='\\';
			s[j++]='n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++]=t[i];
			break;
		}
		++i;
	}
	s[j] = '\0';
}

void convEscapes(char t[], char s[]){
	int i = 0;
	int j = 0;
	while(t[i] != '\0'){
		switch(t[i]){
		case '\\':
			if(t[i+1] == 'n'){
				s[j++] = '\n';
				i++;
			}else if(t[i+1] == 't'){
				s[j++] = '\t';
				i++;
			}else{
				s[j++] = t[i];
			}
			break;
		default:
			s[j++] = t[i];
			break;
		}
		++i;
	}
	s[j] = '\0';
}
