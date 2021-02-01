#include <stdio.h>
#define BODYLINES 40
#define HEADER 3
#define FOOTER 2
#define MAXLINE 120

void printfile(FILE *fp,char *title);
void printheader(char *title, int page);
void printfooter();

int main(int argc, char *argv[]){
    FILE *fp;
    char *title;

    while(--argc > 0){
        if((fp = fopen(*++argv, "r")) == NULL)
            fprintf(stderr, "Error opening file: %s\n", *argv);
        else{
            title = *argv;
            printfile(fp, title);
            fclose(fp);
        }
    }
    return 0;
}


void printfile(FILE *fp,char *title){
    int page = 1, bline = 1;
    char *f;
    char line[MAXLINE];
    printheader(title, page++);
    f = fgets(line, MAXLINE, fp);
    while(f == line){
        if(bline < BODYLINES){
            fprintf(stdout, "%s", line);
            bline++;
        }else{
            printfooter();
            printheader(title, page++);
            fprintf(stdout, "%s", line);
            bline = 1;
        }
        f = fgets(line, MAXLINE, fp);
    }
    printfooter();
    fprintf(stdout, "\f");
}

void printheader(char *title, int page){
    fprintf(stdout, "%s, page: %d\n", title, page);
    for(int i = 1; i < HEADER; ++i)
        fprintf(stdout, "\n");
}

void printfooter(){
    for(int i = 0; i < FOOTER; i++)
        fprintf(stdout, "\n");
    fprintf(stdout, "\f"); 
}
