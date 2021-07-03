#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


int dot(int *a, int *b);
int dot_multi(int *a, int *b);

int product = 0;

int main()
{
    return 0;
}

int dot(int *a, int *b)
{
    int res = 0;
    for (int i = 0; a[i] != NULL; i++)
        res += a[i] * b[i];
    return res;
}

int dot_multi(int *a, int *b)
{
    int res = 0;

    return res;
}