#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long dot(int *a, int *b);
int *random_array(int size);
int *cross_product(int *a, int *b, int length);

int product = 0;

int main(int argc, char **argv)
{
    if (argc < 2)
        exit(1);

    // convert user input string to integer
    int n = atoi(argv[1]);

    // use current time as a random generator seed
    srand(time(0));

    int *a = random_array(n);
    int *b = random_array(n);

    int i = 0;
    // long long res = dot(a, b);
    int *prod = cross_product(a, b, n);
    // while (*prod != NULL)
    //     printf("Dot product = %d\n", *prod++);
    printf("Done!");
    return 0;
}

long long dot(int *a, int *b)
{
    long long res = 0;
    for (int i = 0; a[i] != NULL; i++)
        res += a[i] * b[i];
    return res;
}

int *random_array(int size)
{
    int *arr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int r;
        while ((r = (rand() % ((size * 3) + 1 - (size * -3))) + (size * -3)) == 0)
            ;
        arr[i] = r;
    }
    return arr;
}

int *cross_product(int *a, int *b, int length)
{
    int *product = calloc(length, sizeof(int));
    for (int i = 0; i < length; i++)
        product[i] = a[i] * b[i];
    return product;
}

void *cross_threaded(void *a, void *b, void *length)
{
    int *arr1 = (int *)a;
    int *arr2 = (int *)b;
    int size = (int) length;
    int *prod = calloc(size, sizeof(int));
    
    for (int i = 0; i < size; i++) {
        int r;
        while ((r = (rand() % ((size * 3) + 1 - (size * -3))) + (size * -3)) == 0)
            ;
        prod[i] = r;
    }
    pthread_exit(NULL);
}

int **transpose(int **a, int xdim, int ydim)
{
    int row, col;
    int **tr = calloc(ydim, sizeof(int));
    for(row = 0, col = 0; row < ydim || col < xdim; row++, col++)
        tr[col][row] = a[row][col];
    return tr;
}