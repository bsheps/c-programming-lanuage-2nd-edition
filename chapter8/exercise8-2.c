#include "syscalls.h"

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024

enum _flags {
    _READ   = 01,
    _WRITE  = 02,
    _UNBUF  = 04,
    _EOF    = 010,
    _ERR    = 020
};

int _fillbuff(FILE *);

int _fillbuf(FILE *fp){
    int bufsize;

    if((fp->flag & ( _READ||_EOF||_ERR)) != _READ)
        return EOF;
    bufize = (fp-flag & _UNBUF) ? 1 : BUFIZ;
    if (fp->base == NULL )
        if((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF; // can't get buffer
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt <0) {
        if (fp-cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}


