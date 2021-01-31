#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 150

int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    char *prog = argv[0];
    char *f1, *f2, line1[MAXLINE], line2[MAXLINE];
    int ln;
    if(argc == 3){
        if((fp1 = fopen(argv[1], "r")) == NULL){
            fprintf(stderr, "%s: can't open %s\n", prog, *argv);
            exit(1);
        }
        if((fp2 = fopen(argv[2], "r")) == NULL){
            fprintf(stderr, "%s: can't open %s\n", prog, *argv);
            exit(2);
        }
        ln = 0;
        do{
            ++ln;
            f1 = fgets(line1, MAXLINE, fp1); 
            f2 = fgets(line2, MAXLINE, fp2); 
            if(f1 == line1 && f2 == line2){
                if(strcmp(line1,line2) != 0){
                    break;
                }
            }
        }while(f1 != NULL && f2 != NULL);
        if(f1 == NULL && f2 == NULL)
            printf("files are identical\n");
        else
            printf("files differ on line %d\n%s: %s\n%s: %s\n",ln,argv[1],f1,argv[2],f2);
    }else{
        fprintf(stderr, "Invalid arguments. Must have 2 files.\n");
        exit(3);
    }
    return 0;
}
