#include <stdio.h>

#define MAXIMUM 100

int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXIMUM];
    while ((len = getLine(line, MAXIMUM)) > 1)
        printf("%s has size of %d", line, len);
    
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1; ++i)
    c = getchar();
    if (c != EOF)
        if (c == '\n')
            ++i;
        s[i] = c;
    s[i] = '\0';
    return i;
}