#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
node_t *addtree(node_t *, char *);
void printtree(node_t *);
int getword(char *, int);

typedef struct node {
    char *word;
    int count;
    node_t *left;
    node_t *right;
} node_t;

int main()
{
    char word[MAXWORD];
    node_t *root = NULL;
    while (scanf(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);

    treeprint(root);
    return 0;
}

node_t *talloc(void);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct treenode *addtree(node_t *p, char *w)
{
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(node_t *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a node_t */
node_t *talloc(void)
{
    return (node_t *) malloc(sizeof(node_t));
}

/* make a duplicate of s */
char *strdup(char *s)
{
    char *p;

    p = malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}