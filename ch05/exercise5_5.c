#include <stdio.h>
#define MAXLINE 1000

void getLine(char *s, int max);

int main()
{
    char line[MAXLINE];
    getLine(line, MAXLINE);
    printf("%s\n", line);
    return 0;
}

void getLine(char *s, int lim)
{
    int c;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
}

