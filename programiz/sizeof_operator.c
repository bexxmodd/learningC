#include <stdio.h>

int main()
{
    int integerType;
    float floatType;
    char charType;
    double doubleType;

    printf("Size of an integer is %ld\n", sizeof(integerType));
    printf("Size of an float is %ld\n", sizeof(floatType));
    printf("Size of an character is %ld\n", sizeof(charType));
    printf("Size of an double is %ld\n", sizeof(doubleType));

    return 0;

}