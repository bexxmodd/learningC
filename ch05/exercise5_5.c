#include <stdio.h>
#define MAXLINE 1000

int getLine(char *s, int max);

int main()
{
    char line[MAXLINE];
    getLine(line, MAXLINE);
    printf("%s\n", line);
    return 0;
}

int getLine(char *s, int lim)
{
    int c, len;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
        len++;
    if (c == '\n')
        *s++ = c;
        len++;
    *s = '\0';
    return len;
}

