#include <stdio.h>
#include <stdlib.h>

int multiply(int a, int b);
void printName(char *name);

int main()
{
    int c;
    int (*p)(int, int); // declaring a function pointer
            // e.i. this pointer can hold the frame address of the function
    p = &multiply;
    c = (*p)(3,4);
    printf("%d\n", c); // de-referencing and executing the function

    /*--- we can do the same like this ---*/
    int (*q)(int, int);
    q = multiply;
    c = q(3,5);
    printf("%d\n", c); // de-referencing and executing the function

    void (*p1)(char *);
    char name[] = "Beka";
    p1 = &printName;
    p1(name);

    return 0;
}

int multiply(int a, int b)
{
    return a * b;
}

void printName(char *name)
{
    printf("\thello %s\n", name);
}
