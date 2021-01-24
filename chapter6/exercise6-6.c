#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

/* hash: form hash value for string s*/
unsigned hash(char*s){
    unsigned hashval;

    for(hashval= 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *lookup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install (char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name )) == NULL ) {
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else
        free((void *) np->defn);
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

int undef(char *s){
    struct nlist *np, *prev = NULL;
    int n = hash(s);
    for (np = hashtab[n]; np != NULL; np = np->next){
        if (strcmp(s, np->name) == 0){
            if(prev == NULL){
               hashtab[n] = np->next; 
            }else{
                prev->next = np->next;
            }
            free((void *) np->defn);
            free((void *) np->name);
            free((void *) np);
            return 1;
        }
        prev = np;
    }
    return 0;
}

void printhastab(){
    struct nlist **tab;
    tab = hashtab;
    for(int i = 0; i < HASHSIZE; i++)
        for(struct nlist *np = tab[i]; tab[i] && np; np = np->next)
            printf("(%s,%s)%s", np->name, np->defn, np->next == NULL ? "\n" : " ");
}

int getword(char *word, int lim);

#define MAXWORD 100
#define YES 1
#define NO 0

int main (){
    char word[MAXWORD], prev[MAXWORD], name;
    int c;
    prev[0] = '\n';
    prev[1] = '\0';

    for(;getword(word, MAXWORD) != EOF; strcpy(prev, word)){
        if(prev[0] = '\n' && strcmp(word, "#define") == 0){
            getword(word,MAXWORD);
            strcpy(prev, word); // our name
            getword(word,MAXWORD); // our defn
            install(prev, word); 
        }
    }
    printhastab();
    return 1;
}
/*
int getword(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()) && c != '\n')
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c) && c != '#'){
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
*/

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

