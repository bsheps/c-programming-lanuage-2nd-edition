#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int ch;
    if(strcmp(argv[0], "./lower") == 0){
        while((ch=getchar()) != EOF)
            putchar(tolower(ch));
    }else{
        while((ch=getchar()) != EOF)
            putchar(toupper(ch));
    }
    return 1;
}

