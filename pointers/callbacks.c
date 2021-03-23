#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function pointers can be passed as args to functions

void A();
void B(void (*ptr)());
void bubblesort(int *arr, int size, int (*compare)(int,int));
int compare(int a, int b);
int absolutecompare(int a, int b);

int main()
{
    void (*p)() = A;
    B(p); // we can also just call B(A) as A is a callback function

    int i, nums[] = {5, 3, 1, 4, 9, 0, 2};
    size_t size = (int) sizeof(nums) / sizeof(nums[0]);
    bubblesort(nums, size, compare);
    for (i = 0; i < size; i++)
        printf("%d\t", nums[i]);
    printf("\n");

    int nums1[] = {-55, 3, 1, 4, -19, 20, -2, 43};
    size = (int) sizeof(nums1) / sizeof(nums1[0]);
    bubblesort(nums1, size, absolutecompare);
    for (i = 0; i < size; i++)
        printf("%d\t", nums1[i]);
    printf("\n");

    return 0;
}

void A()
{
    printf("I'm function A\n");
}

void B(void (*ptr)()) // function pointer as arg
{
    ptr(); // call-back function that ptr points to
    printf("Inside of function B\n");
}

/* callback function should compare two ints, 
returns 1 if first el has higher rank,
and -1 if second el has higher rank */
void bubblesort(int *arr, int size, int (*compare)(int,int))
{
    int i, j, tmp;
    for (i = 0; i < size; i++)
        for (j = 0; j < size-1; j++) {
            if (compare(arr[j], arr[j+1]) > 0) { //compare arr[j] with arr[j+1] and swap if needed
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
}

int compare(int a, int b)
{
    return a - b;
}

int absolutecompare(int a, int b)
{
    return abs(a) - abs(b);
}