#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int** data;
    unsigned int length;
    unsigned int used;
} arraylist;

arraylist* constructor(int** data, int size);

int main()
{
    int* arr = (int*) calloc(sizeof(int), 5);
    for (int i = 0; i < 5; i++) {
        arr[i] = 2;
    }


    int** ptr_to_arr = &arr;
    arraylist* list;
    list = constructor(ptr_to_arr, 5);

    printf("Size of list: %d\n", list->used);
    printf("Capacity list: %d\n", list->length);
    ///////////////////////////////////
    for (int i = 0; i < 5; i++)
        printf("Pointer to: %p\t", list->data[i]);
    ///////////////////////////////////
}

arraylist* constructor(int** data, int size)
{
    arraylist* list;
    list = (arraylist*) malloc(sizeof(arraylist));
    list->data = data;
    list->used = size;

    int len = INITIAL_CAPACITY;

    while (len <= size)
        len *= 2;

    list->length = len;
    return list;
}
