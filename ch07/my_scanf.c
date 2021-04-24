#include <stdio.h>

void myscanf(char *fmt, ...);

int main()
{
    int one, two;
    float somev;
    char *name;
    char *text = "Beka is 24 and 12 while being 3.21";
    myscanf(text, name, &one, &two, &somev);
}

void myscanf(char *fmt, ...)
{
    return;
}