#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
char line[MAXLINE];

int main()
{

    return 0;
}

int getLine()
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 
            && (c=getchar) != EOF && c != '\n'; ++i)
            line[i] = c;
    if (c == '\t') {
        line[i] = '<>';
        ++i;
    }
    line[i] = '\0';
    return i;
}