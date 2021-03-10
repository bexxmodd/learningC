#include <stdio.h>
#include "strings.h"
#include "exercise5_5.h"

#define MAXLEN 1000 // max length of any input line
#define MAXLINES 5000

char *lineptr[MAXLINES];

int getLine(char *s, int max);
void strCpy(char *s, char *t);

/* read input lines */
int readLines(char *lineptr[], char *s, int maxlines)
{
    int len;
    char line[MAXLEN];

    int nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || s == NULL)
            return -1;
        else {
            line[len-1] = '\0'; // delete newline
            strCpy(s, line);
            lineptr[nlines++] = s++;
        }
    }
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

int main()
{
    char *lines[5000];
    char s[5000];
    int c = readLines(lineptr, s, 1000);
    writelines(lineptr, c);

    return 0;
}