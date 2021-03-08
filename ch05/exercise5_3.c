#include <stdio.h>

char *strCat(char *s, char *t);
void strCpy(char *s, char *t);
int strLen(char *s);

/* concatenate t to end of s; s must be big enough */
char *strCat(char *s, char *t)
{
    strCpy(s + strLen(s), t);
    return s;
}

/* copy t to s: pointer version 3 */
void strCpy(char *s, char *t)
{
    while (*s++ = *t++);
}

/* strlen: return length of s */
int strLen(char *s)
{
    int i = 1;
    while (*s++)
        i++;
    return i;
}

int main()
{
    char s[] = "Hello";
    char t[] = " World";
    printf("%s\n", strCat(s, t));

    return -1;
}