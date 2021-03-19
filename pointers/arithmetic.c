#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;

    // when we increment *p by one (for example) as it's an integer 
    // the address it's pointing to will be increment by four
    printf("%ld\n", p);
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("%ld\n", p+1);

    // pointer variables are strongly typed. To store a pointer we need to
    // create a type of pointer that stores address of a similar type of variable.


    int c = 1025;
    int *ptr;
    ptr = &c;
    printf("Address = %ld, value = %d\n", ptr, *ptr);

    char *p0;
    p0 = (char*) ptr;
    printf("Size of char is %ld bytes\n", sizeof(char));
    printf("Address = %ld, value = %d\n", p0, *p0);

    // If you want a generic pointer use can create a void pointer
    void *p1;

    // If we store the address of the pointer in a pointer we need two '*' after type:
    int **q;
    q = &p0; // pointer that points to the address of p0

    // int **q -> int *p -> int x;

    return 0;
}