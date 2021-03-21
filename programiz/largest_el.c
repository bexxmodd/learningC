#include <stdio.h>

int largestel(int* arr);

int main()
{
    int arr[] = {5, 2, 6, 12, 0, 2};
    printf("Max = %d\n", largestel(arr));
    return 0;
}

int largestel(int* arr)
{
    int max = 0;
    for (;*arr != '\0'; *arr++)
        if (*arr > max)
            max = *arr;
    return max;
}