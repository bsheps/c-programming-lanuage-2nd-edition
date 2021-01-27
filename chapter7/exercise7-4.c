#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>

#define MAX 100
void minprintf(char *fmt, ...);
void minscanf(char *fmt, ...);

int main(){
    int a,b,c,d,e,f;
    char name[MAX];
    float flo;
    printf("idfsxXuo\n");
    minscanf("%i%d%f%s%x%X%u%o\n",&a,&b,&flo,name,&c,&d,&e,&f);
    minprintf("%i%d%f%s%x%X%u%o\n",a,b,flo,name,c,d,e,f);
    return 0;
}

void minscanf(char *fmt, ...){
    va_list ap;
    char *p, *sval, input[MAX];
    int *ival;
    float *dval;
    unsigned *uval;
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
                ival = va_arg(ap, int *);
                scanf(input, ival);
                break;
            case 'f':
                dval = va_arg(ap, float *);
                scanf(input, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(input, sval);
                break;
            case 'x':
            case 'X':
            case 'u':
            case 'o':
                uval = va_arg(ap, unsigned *);
                scanf(input, uval);
                break;
            default:
                scanf(input);
                break;
        }
    }
    va_end(ap);
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
