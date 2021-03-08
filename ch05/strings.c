#include <stdio.h>

/* copy t to s: pointer version 3 */
void strcpy(char *s, char *t)
{
    while (*s++ = *t++);
}

/* return -1 if s<t, 0 if s=t, and 1 if s>t */
int strcmp(char *s, char*t)
{
    for ( ;*s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return (*s < *t) ? -1 : 1;
}