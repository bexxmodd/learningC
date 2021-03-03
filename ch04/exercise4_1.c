#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main()
{
    char s[] = "Hello";
    char t[] = "el";
    printf("%d", strindex(s, t));
    return -1;
}

int strindex(char s[], char t[])
{
    int i, k, j;

    for (i = strlen(s)-1; i > -1; i--) {
        for (j=strlen(t)-1, k=i; j > -1 && k > -1; j--, k--)
            if (s[k] == t[j]) {
                return i;
            }
    }
    return -1;
}