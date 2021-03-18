#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;

    // when we increment *p by one (for example) as it's an integer 
    // the address it's pointing to will be increment by four
    printf("%d\n", p);
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("%d\n", p+1);


    return 0;
}