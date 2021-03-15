#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define stdin stdin

int main(int argc, char *argv[])
{
    if (argc < 1)
        return 0;

    char line[MAXLINE];
    long lines = 0;
    int c, n;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch(c) {
                case 'n':
                    n = (int) *argv[1];
                    break;
                default:
                    n = 10;
            }
    while (getline(line, MAXLINE, stdin) > 0 && n > 0) {
        if (strstr(line, *argv) != NULL)
            printf("%s\n", line);
            n--;
    }
}