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

struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *word, int lim);
struct tnode *addTree(struct tnode *p, char *w);
struct tnode *treeAlloc(void);
char *strdup2(char *s);
void buildArr(struct tnode *arr[], struct tnode* root);
void sortArr(struct tnode *arr, int len);
void printarr(struct tnode *p[]);

int distinct;
int i=0;

int main(){
    char word[MAXWORD];
    int out;
    struct tnode *root = NULL;
    distinct = 0;
    while(out=getword(word, MAXWORD) != EOF)
        root = addTree(root, word);
    struct tnode *arr[distinct];
    buildArr(arr, root);
    sortArr(arr, 0, distinct-1);
    printarr(arr);
    return 1;
}

void printarr(struct tnode *p[]){
    for(int i = 0; i < distinct; i++){
        printf("%d\t%s\n", p[i]->count, p[i]->word);
    }
}

void sortArr(struct tnode *arr, int len){
// todo, page 110
}

void buildArr(struct tnode *arr[], struct tnode* p){
    if(p != NULL){
        buildArr(arr, p->left);
        buildArr(arr, p->right);
        arr[i++] = p;
    }
}
struct tnode *sortByCount(struct tnode *p, struct tnode *i){
    
}

struct tnode *addTree(struct tnode *p, char *w){
    int cond;
    if(p == NULL){
        p = treeAlloc();
        p->word = strdup2(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
        ++distinct;
    }else if((cond = strcmp(w, p->word)) == 0){
        p->count++;
    }else if(cond > 0){
        p->right = addTree(p->right, w);
    }else{
        p->left = addTree(p->left, w);
    }
    return p;
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

