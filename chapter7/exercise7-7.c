#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int ggetline(char *line, int max);
/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]){
    char line[MAXLINE];
    long lineno= 0;
    int c, except =0, number =0, found =0;

    while(--argc > 0 && (*++argv)[0]== '-')
        while((c = *++argv[0]))
            switch (c) {
                case 'x':
                    except =1;
                    break;
                case 'n':
                    number =1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc =0;
                    found = -1;
                    break;
        }
    printf("argc: %d\n", argc);
    if(argc < 1)
        printf("Usage: find -x -n pattern <optional files>\n");
    else{
        char *pattern = *++argv;

        if(argc == 1) // read from stdin
            while (ggetline(line, MAXLINE) > 0){
                lineno++;
                if ((strstr(line, *argv) != NULL) != except) {
                    if(number)
                        printf("%ld: ", lineno);
                    printf("%s", line);
                    found++;
                }
            }
        else{ // read from file(s)
            char *fl;
            FILE *fp;
            do{
                if((fp = fopen(*++argv, "r")) == NULL){
                    fprintf(stderr, "Error opening file: %s\n",*argv);
                    continue;
                }else{
                    do{
                        fl = fgets(line, MAXLINE, fp);
                        lineno++;
                        if((strstr(line, pattern) !=NULL) != except){
                            printf("(%s) ", *argv);
                            if(number)
                                printf("line %ld: ", lineno);
                            printf("%s\n", line);
                            found++;
                        }
                    }while(fl == line);
                    fclose(fp);
                    lineno = 0;
                }
            }while(--argc > 0);
        }
    }
    return found;
} 

int ggetline(char *s, int lim){
	int c;
	char *p;
	p = s;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if(c == '\n')
		*p++ = c;
	*p = '\0';
	return p - s;
}
