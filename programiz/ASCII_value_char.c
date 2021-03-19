#include <stdio.h>

int main()
{
    char c;
    printf("Enter a character\n");
    scanf("%c", &c); // store enter char at the address of `c`

    // %d displays the integer value of a character
    // %c displays the actual character
    printf("ASCII value of %c is %d\n", c, c);

    return 0;
}