#include <stdio.h>

int toLower(int c);

int main()
{
    char abs[] = "ABCDEFG";
    for (int i = 0; i < sizeof(abs); i++)
        printf("%c ", toLower(abs[i]));
    return -1;
}

/* toLower: conversts c to lower case; ASCII only */
int toLower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}