#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    char what[100];
    strcpy(what, argv[1]);

    int c;

    while ((c = getchar()) != EOF)
        if (strcmp(what, "upper") == 0)
            putchar(toupper(c));
        else if (strcmp(what, "lower") == 0)
            putchar(tolower(c));
    return 0;
}