#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>

#define MAX 100
void minprintf(char *fmt, ...);

int main(){
    minprintf("%i%d%f%s%x%X%u%o\n", 1,2,3.33,"hello",31,31,31,31);
    return 0;
}
void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval, input[MAX];
    int ival;
    double dval;
    unsigned uval;
    int i;

    va_start(ap,fmt);
    for(p = fmt; *p; p++){
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        for(i = 1, input[0] = *p; *(p+1) && !isalpha(*(p+1));i++)
            input[i] = *++p;
        input[i] = *++p;
        input[i +1] = '\0';
        switch(input[i]) {
            case 'i':
            case 'd':
                ival = va_arg(ap, int);
                printf(input, ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(input, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(input, sval);
                break;
            case 'x':
            case 'X':
            case 'u':
            case 'o':
                uval = va_arg(ap, unsigned);
                printf(input, uval);
                break;
            default:
                printf(input);
                break;
        }
        printf("\n");
    }
    va_end(ap);
}
