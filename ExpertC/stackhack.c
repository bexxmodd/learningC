#include <stdio.h>

void printSomething();

int main()
{
    long i;
    printf("The stack top is near %p\n", &i);
    printSomething();
    printf("The stack top is near %p\n", printSomething);
    int arr[] = {5, 2, 5, 1, 2, 7, 8};
    printf("The stack top is near %p\n", arr);
    return 0;
}

void printSomething()
{
    int a = 24;
    printf("   ignore me: %d\n", a);
}