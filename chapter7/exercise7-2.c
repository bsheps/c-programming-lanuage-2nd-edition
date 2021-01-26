#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int main(){
    int ch, lc;
    while((ch=getchar())!=EOF){
        if(32 < ch && ch < 126){ // ascii graphical chars
            putchar(ch);
            lc++;
        }else if(ch == '\n'){
            putchar(ch);
            lc = 0;
        }else{
            printf("%02X",ch); // ascii non-graphical chars
            lc++;
        }
        if(lc >= MAXLINE){
            putchar('\n');
            lc = 0;
        }
    }
    return 1;
}
