#include <stdio.h>

// int allocates 4 bytes of memory in RAM
// char - 1 byte
// float - 4 bytes


int main()
{
    int a;

    int *p; // defines pointer "p" which will point to some address in memory.
    p = &a; // "&" in front of a variables gives us the address of that variable e.g. returns a pointer.

    a = 19;

    printf("%d\n", *p); // prints the value of variable pointer `p points to (in this case it's `a`)
    printf("%d\n", *p); // this is called derefrencing - we'll print a value at the address `p` points to.
    printf("%d\n", &a); // will print the memory address of where `a` is stored

    printf("%d\n", a);
    *p = 13; // dereferencing - value at address being pointed by `p` is equal 13
    printf("%d\n", a); // value will be now changed



    return 0;
}

