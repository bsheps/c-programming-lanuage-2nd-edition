#include <stdio.h>

int main(){
	char c[20] = "Help";
	char *s;
	s = c; 
	printf("init: %s\n",s); // Help
	++*s;
	printf("++*s: %s\n",s); // "Ielp" ascii increment of first element
	++(*s);
	printf("++(*s): %s\n",s); // "Jelp" ascii increment of first element
	*s++;
	printf("*s++: %s\n",s); // "elp" moves to next element in array
	(*s)++;
	printf("(*s)++: %s\n",s); // "flp" ascii increment of current element
	*(++s);
	printf("*(++s)\n: %s\n",s); // "lp" moves to next element
	*++s;
	printf("*++s\n: %s\n",s); // "p" moves to next element
	return 0;
}

