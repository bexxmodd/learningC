#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100


long long dot(int *a, int *b);
int *random_array(int size);

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
    long long res = dot(a, b);
    printf("Dot product = %llu", res);
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
        arr[i] = (rand() % (size * size)) + 1;
    return arr;
}