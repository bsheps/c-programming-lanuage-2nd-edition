#include <ctype.h>
#include <stdio.h>

// double atof(char s[]);

int main(){
	double atof(char []);
	char t1[] = "123.456";
	char t2[] = "123.456e0";
	char t3[] = "123.456e-3";
	char t4[] = "123.456e-6";
	char t5[] = "123.456e3";
	char t6[] = "123.456e6";
	char t7[] = "123.456e10";
	char t8[] = "-123.456e10";
	printf("%s = %f\n",t1, atof(t1));
	printf("%s = %f\n",t2, atof(t2));
	printf("%s = %f\n",t3, atof(t3));
	printf("%s = %f\n",t4, atof(t4));
	printf("%s = %f\n",t5, atof(t5));
	printf("%s = %f\n",t6, atof(t6));
	printf("%s = %f\n",t7, atof(t7));
	printf("%s = %f\n",t8, atof(t8));
	return 0;
}

/* convert string s to double.
extend to handle scientific notation of the form 123.45e-6
where floating point may be followed by e or E and an optionally signed exponent
*/
double atof(char s[]){
	double val, power, exp, magnitude;
	int i, sign, expSign;

	for(i = 0; isspace(s[i]); i++) // skip whitespaces
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if(s[i] == 'e' || s[i] == 'E'){
		i++;
		expSign = s[i] == '-' ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(exp = 0.0; isdigit(s[i]); i++)
			exp = 10.0 * exp + (s[i] - '0');
		for(magnitude = 1.0; exp > 0; exp--)
			magnitude *= 10;	
		double input = sign * val / power;
		return expSign > 0 ? input * magnitude : input / magnitude;
		
	}else{
		return sign * val / power;
	}
}
