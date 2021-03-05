#include <stdio.h>

#define swap(t,x,y) t = x, x = y, x = t

int main()
{
    int t;
    int x = 5;
    int y = 7;
    swap(t,x,y);
    printf("x=%d and y=%d", y, x);
}