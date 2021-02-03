#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void io(int fd, int out);

int main(int argc, char *argv[]){
    int fd;
    if(argc == 1)
        io(0, 1);
    while(--argc > 0){
        if((fd = open(*++argv, O_RDONLY, 0)) == -1){
            fprintf(stderr,"Error opening %s\n", *argv);
        }else{
           io(fd, 1); 
           close(fd);
        }
    }
    return 1;
}

void io(int input, int output){
    char buf[BUFSIZ];
    int n;

    while((n=read(input, buf, BUFSIZ)) > 0)
        write(output, buf, n);
}
