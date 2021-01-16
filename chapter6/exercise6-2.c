struct tnode{
    char *word;
    int isMatch;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NO 0
#define YES 1

int getword(char *, int);
int comparer(char *test, struct tnode *p, int *matched);
char *strdup2(char *s);
struct tnode *treeAlloc(void);
void treeprint(struct tnode *p);
struct tnode *addtree(struct tnode *p, char *w, int *matched);
int num = 6;

/* print alphabetically words that match the first n chars of the word*/
int main(int argc, char *argv[]){
    struct tnode *root = NULL;
    char word[MAXWORD];
    int matched;
    if(argc == 2)
        num = atoi(*++argv);
    while (getword(word,MAXWORD) != EOF){
        matched = NO;
		if(isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root, word, &matched);
    }
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int *matched){
    int cond;
    if(p == NULL){
        p = treeAlloc(); // make new node
        p->word= strdup2(w);
        p->isMatch = *matched;
        p->left = NULL;
        p->right = NULL;
    }else if((cond = comparer(w, p, matched)) < 0)
        p->left = addtree(p->left, w, matched);
    else if(cond > 0)
        p->right = addtree(p->right, w, matched);
    return p;
}

int comparer(char *test, struct tnode *p, int *matched){
    char *pw;
    pw = p->word;
    int i;
//    printf("c: %s\n",test);
    for(i = 0; *test == *pw; i++, test++, pw++)
        if(*test == '\0')
            return 0;
    if(i >= num){
        *matched = YES;
        p->isMatch = YES;
    }
    return *test - *pw;
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        if(p->isMatch)
            printf("%s\n", p->word);
        treeprint(p->right);
    }
}

struct tnode *treeAlloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup2(char *s){
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(isalpha(c) || c == '_' || c == '#'){ // handle underscores and preprocessor
	    for ( ; --lim > 0; w++)
	    	if(!isalnum(*w = getch()) && *w != '_'){
	    		ungetch(*w);
	    		break;
	    	}
		*w = '\0';
		return word[0];
	}else if(c == '\'' || c == '"'){ // ignore strings
        for( ; --lim > 0; w++){
            if((*w = getch()) == '\\') // multi-line string
                *++w = getch();
            else if(*w == c){ // end of string
                ++w;
                break;
            }else if(*w == EOF){
                break;
            } 
        }
        *w = '\0';
        return word[0];
    }else if(c == '/'){ // ignore commented code
        int c2 = getch();
        if(c2 == '/') // ignore rest of line
            while(c2 != '\n' && c2 != EOF)
                c2 = getch();
        else if(c2 == '*'){ // extended comment section
            while((c2 = getch()) != EOF) // cycle thru until comment closure
                if(c2 == '*')
                    if((c2 = getch()) == '/')
                        break;
                    else
                        ungetch(c2);
        }
    }
	*w = '\0';
	return c;
}


#define BUFSIZE	100

char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf

int getch(void){	// get a (possibly pushed back) character
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c){	// push character back on input
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

