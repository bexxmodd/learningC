#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//< produces random float value
#define fraud() ((double) rand() / (RAND_MAX+1.0))

int main()
{
    system("vizexdf -s type");
    return 0;
}

bool my_isupper(char c)
{
    if (c >= 65 || c <= 90)
        return true;
    return false;
}