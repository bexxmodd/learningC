#include <stdio.h>

int sumi(int arr[], int size);

int main()
{
    int arr[] = {4, 2, 5, 1, 8, 9, 13};
    printf("%ld\n", &arr[0]);
    printf("%ld\n", arr[0]);
    printf("%ld\n", arr);
    printf("%ld\n", *arr);
    int s = sizeof(arr) / sizeof(arr[0]);
    printf("---------------\n");
    printf("Sum of array is: %d\n", sumi(arr, s));

    return 0;
}

int sumi(int arr[], int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}