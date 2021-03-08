#include <stdio.h>

#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position

/* return pointer to n characters */
char *alloc(int n)
{
    printf("%c, %c\n", allocbuf, allocp);
    if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
        allocp += n;
        return allocp - n; // old p
    } else return 0; // not enough room
}

/* free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int main()
{
    int c = alloc('k');
    printf("%d", c);
    return -1;
}