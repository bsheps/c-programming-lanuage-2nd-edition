/* LEFT OFF HERE
 * I need to add to tree
 * Create print method to validate everything is working
 * Then add else if search and find to add additional line numbers (avoid duplicate
 * line numbers). Validate that works via print.
 * Finally remove noise words.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct lnode{
    int linenum;
    struct lnode *next;
};

struct tnode{
    char *word;
    struct lnode *lnLL;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *word, int lim);
struct tnode *updateTree(struct tnode *p, char *w, int num);
void addline(struct lnode *node, int num);
struct lnode *newlnode(int num);
struct tnode *treeAlloc(void);
char *strdup2(char *s);
struct lnode *lineAlloc(void);
void treeprint(struct tnode *p);

int main(){
    char word[MAXWORD];
    int out, linenum = 1;
    struct tnode *root = NULL, *node;

    while(out=getword(word, MAXWORD) != EOF){
        if(*word == '\n')
            ++linenum;
        else{
            root = updateTree(root, word, linenum);
        }
    }
    treeprint(root);
    return 1;
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%s - ", p->word);
        struct lnode *node;
        for(node = p->lnLL; node != NULL; node = node->next)
            printf("%d%s", node->linenum, node->next != NULL ? ", " : "\n");
        treeprint(p->right);
    }
}
struct tnode *updateTree(struct tnode *p, char *w, int num){
    int cond;
    if(p == NULL){
        p = treeAlloc();
        p->word = strdup2(w);
        p->lnLL = newlnode(num);
        p->left = NULL;
        p->right = NULL;
    }else if((cond = strcmp(w, p->word)) == 0){
        addline(p->lnLL, num);
    }else if(cond > 0){
        p->right = updateTree(p->right, w, num);
    }else{
        p->left = updateTree(p->left, w, num);
    }
    return p;
}

void addline(struct lnode *node, int num){
    while(node->next != NULL)
        node = node->next;
    node->next = newlnode(num);
}

struct lnode *newlnode(int num){
    struct lnode *node = lineAlloc();
    node->linenum = num;
    node->next = NULL;
    return node;
}

struct lnode *lineAlloc(void){
    return (struct lnode *) malloc(sizeof(struct lnode));
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

	while (isspace(c = getch()) && c != '\n')
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
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

