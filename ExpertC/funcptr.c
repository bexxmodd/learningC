#include <stdio.h>

int compare(int a, int b)
{
        if (a > b)
                return -1;
        else
                return 1;
}

void a_func()
{
        printf("Hello\n");
}

void b_func(void (*ptr)())
{
        ptr();
}

void bubble_sort(int arr[], int n, int (*cmpr)(int,int))
{
        // simple bubble sort
       int i, j, tmp;
       for (i = 0; i < n; i++)
               for (j = 0; j < n-1; j++) {
                       if (compare(arr[j], arr[j+1]) > 0) {        
                               tmp = arr[j];
                               arr[j] = arr[j+1];
                               arr[j+1] = tmp;
                       }
               }
}

int main()
{
        b_func(a_func);
        int nums[] = {3,2,1,5,6,4,7};

        bubble_sort(nums, 7, compare);
        for (int i = 0; i < 7; i++)
                printf("%d ", nums[i]);

        return 0;
}


