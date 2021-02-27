#include <stdio.h>

#define MAXLINE 100

int getLines(char s[], int lim);
void reverse(char s[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLines(line, MAXLINE)) > 1) {
        reverse(line, len);
        printf("%s\n", line);
    }

    return 0;
}

/* getlines: read a line into s, return length */
int getLines(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[], int len)
{
    int size = len - 1;
    char reversed[len];

    for (int i = 0; i < len; i++)
        reversed[i] = s[size--];

    int i;
    i = 0;
    while((s[i] = reversed[i]) != '\0')
        ++i;
}