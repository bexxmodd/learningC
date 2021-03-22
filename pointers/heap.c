#include <stdio.h>
#include <stdlib.h>

int main()
{
    // functions used to allocate dynamic memory
    /* malloc, calloc, realloc, free */

    int a; // goes on stack
    int i; // goes on stack
    
    // to reserver space allocated on heap
    /*--------- malloc ---------*/
    // void *malloc(size_t size);
    int *p;
    p = (int *) malloc(sizeof(int)); // asks how much memory to allocate in bytes
                    // returns a pointer to the starting addres of allocated space
            // we also did a type casting b/c malloc returns a `void` type pointer

    // if we want to fill in at address p we need to dereferance
    *p = 10;

    // once we are done using a pointer to the heap we need to clear it
    free(p);

    // if we want to allocate the array space on heap 
    // we call size times number of items in the array
    p = (int*) malloc(3 * sizeof(int));
    
    // All the data manipulation on dynamic memory happens thorugh the pointers

    /*--------- calloc ---------*/
    // void * calloc(size_t num, size_t size);
    // num: of elements. size: of a data type
    int *q = (int*) calloc(3, sizeof(int));

    // malloc doesnt initialize bytes with any value
    // calloc sets all byte positions with value 0
    printf("values via calloc: ");
    for (i = 0; i < 3; i++)
        printf("%d\t", *q++);
    printf("\n");


    /*--------- realloc ---------*/
    // if you want to change the size of already allocated dynamic memory
    // void * realloc(void * ptr, size_t size);
    // ptr: pointer of the block beginning. size: of the new memory block

    float *f = (float*) realloc(p, sizeof(float));

    /*--------------------------------------*/
    int n;
    printf("Enter size of an array:\n");
    scanf("%d", &n);
    char *A = (char*) malloc(n*sizeof(char));

    char c = 'a';
    for (i = 0; i < n; i++)
        A[i] = c + i;
    for (i = 0; i < n; i++)
        printf("%c\t", A[i]);
    printf("\n");
    
    return 0;
}