#include <stdio.h>
#include <stdlib.h>

int *add(int *a, int *b);

int main()
{
    int a = 2, b = 4;
    printf("------- in main() -------\n");
    printf("Address of a: %ld. Address of b: %ld\n", &a, &b);
    printf("Value of a: %d. Value of b: %d\n", a, b);
    int *p = add(&a, &b);
    printf("\n------- in main() -------\n");
    printf("Sum is located at: %ld\n", p);
    printf("Sum values is %d\n", *p);
    free(p);

    return 0;
}

// We are passing the address of the variables 
// instead of making a copy for add function
int *add(int *a, int *b)
{
    printf("\n------- in add() -------\n");
    printf("Address of a: %ld. Address of b: %ld\n", a, b);
    printf("Value of a: %d. Value of b: %d\n", *a, *b);
    int *c = (int*) malloc(sizeof(int));
    *c = (*a) + (*b);

    // We can't just return the address for c as after Add is done executing
    // it's allocated memory of stack will be erased/overriden
    // instead we first allocate the space for c on heap and than return its address
    printf("Sum is located at: %ld\n", c);
    printf("Sum values is %d\n", *c);
    return c;
}