#include <stdio.h>

long reverseNumber(long n);
int palindrom(long n);

int main()
{
    long num;
    int pal;
    printf("Please enter the number you want to reverse:\n");
    scanf("%ld", &num);
    printf("%ld\n", reverseNumber(num));

    pal = palindrom(num);
    if (pal > 0)
        printf("%ld is also a palindrom\n", num);
    else
        printf("%ld is not a palindrom\n", num);
    
    return 0;
}

long reverseNumber(long n)
{
    long remainder, rev = 0;

    while (n != 0) {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    return rev;
}

int palindrom(long n)
{
    long reversed;
    reversed = reverseNumber(n);
    return reversed == n ? 1 : -1;
}