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

int main (){
    char *words[] ={"attract",
    "guard",
    "scratch",
    "recognize",
    "cancel",
    "commemorate",
    "park",
    "stool",
    "grip",
    "first-hand",
    "resource",
    "shine",
    "mind",
    "seal",
    "important",
    "mole",
    "rescue",
    "agent",
    "tree",
    "end",
    "rib",
    "curriculum",
    "texture",
    "west",
    "position",
    "blank",
    "us",
    "athlete",
    "pastel",
    "main",
    "role",
    "column",
    "limit",
    "digress",
    "repetition",
    "protection",
    "anger",
    "spend",
    "deadly",
    "siege",
    "senior",
    "definition",
    "experience",
    "film",
    "moral",
    "file",
    "provide",
    "sustain",
    "arch",
    "vain",
    "technique",
    "bathroom",
    "heat",
    "ceremony",
    "spot",
    "depart",
    "lemon",
    "porter",
    "board",
    "intention",
    "cruelty",
    "period",
    "earwax",
    "petty",
    "fear",
    "neglect",
    "technology",
    "collar",
    "dash",
    "variation",
    "glimpse",
    "first-hand",
    "joystick",
    "belong",
    "poison",
    "news",
    "twitch",
    "division",
    "bleed",
    "desire",
    "cutting",
    "absorption",
    "trap",
    "guideline",
    "fastidious",
    "mill",
    "bottom",
    "stay",
    "infrastructure",
    "fresh",
    "despair",
    "index",
    "diplomatic",
    "liberal",
    "manufacture",
    "transform",
    "wheel",
    "satisfied",
    "mainstream",
    "spirit",
    "thesis",
    "ecstasy",
    "houseplant",
    "cow",
    "occupation",
    "weakness",
    "directory",
    "pitch",
    "debate",
    "detector",
    "coup",
    "distance",
    "buffet",
    "rocket",
    "indulge",
    "floor",
    "circle",
    "pardon",
    "environmental",
    "identification",
    "muggy",
    "conflict",
    "state",
    "nail",
    "conservation",
    "bitch",
    "therapist",
    "jelly",
    "tail",
    "left",
    "disorder",
    "repetition",
    "draw",
    "divorce",
    "hospital",
    "trick",
    "dilemma",
    "youth",
    "adventure",
    "linger"
    };
    for(int i = 0; i < HASHSIZE; i++)
        hashtab[i] = NULL;
    for(int i = 0; i < 140; )
        install(words[i++],words[i++]);
    printhastab();
    printf("\n\n\n");
    undef("period");
    printhastab();
    return 1;
}
