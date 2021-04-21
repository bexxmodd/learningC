#include <stdio.h>
#include <stdlib.h>

typedef struct nlist {
    char *name; // define name
    char *defn; // replacement text
    nlist *next;
} nlist;

#define HASHSIZE 101

static nlist *hashtable[HASHSIZE]; /* pointer table */
nlist *lookup(char *);
char *strdup(char *);

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != NULL; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: loof ro s in hashtable */
nlist *lookup(char *s)
{
    nlist *np;

    for (np = hashtable[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->next) == 0)
            return np;
    return NULL;
}

/* install: put (name, defn) in hashtab */
nlist *install(char *name, char *defn)
{
    nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = malloc(sizeof(*np));
        if (np == NULL || (np->name == strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtable[hashval] = np;
    } else // already exists
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL) // free previous defn
        return NULL;
    return np;
}

/* undef: remove a name and definition from the table */
nlist *undef(char *s)
{
    nlist *np, *r = NULL;
    for (np = hashtable[hash(s)]; np != NULL; np = np->next)
        if (strcmp(np->name, s) == 0) {
            r = np;
            free(np->name);
            free(np->defn);
            free(np);
        }
    return r;
}