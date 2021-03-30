#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct arraylist {
    int* data; // array that will hold int data
    unsigned int length; // total length of a struct
    unsigned int used; // number of spots filled
} arraylist;

arraylist* constructor(int size);

int main()
{
    arraylist* list;
    list = constructor(5);

    for (int i = 0; i < 5; i++)
        list->data[i] = i*i;

    printf("Size of list: %d\n", list->used);
    printf("Capacity of list: %d\n", list->length);
    for (int i = 0; i < 5; i++)
        printf("%d, ", list->data[i]);
}

arraylist* constructor(int size)
{
    arraylist* list;
    list = (arraylist*) malloc(sizeof(arraylist));
    int* arr = (int*) calloc(sizeof(int), size);

    list->data = arr;
    list->used = 0;
    list->length = size;

    return list;
}


