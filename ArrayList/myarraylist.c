#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_CAPACITY 4

typedef struct arraylist {
    void** data; // array that will hold int data
    unsigned int length; // total length of a struct
    unsigned int capacity; // number of spots filled
} arraylist;

arraylist* arraylist_create();
void arraylist_allocate(arraylist* list, unsigned int size);
void arraylist_append(arraylist* list, void* item);
void* arraylist_get(arraylist* list, unsigned int index);

int main()
{
    arraylist* list;
    list = arraylist_create();
    arraylist_append(list, 2);
    arraylist_append(list, 3);
    arraylist_append(list, 5);

    printf("Size of list: %d\n", list->length);
    printf("Capacity of list: %d\n", list->capacity);
    for (int i = 0; i < 3; i++)
        printf("%d, ", list->data[i]);
    printf("\n");
    printf("Item on index %d is %d\n", 1, (int*) arraylist_get(list, 1));
    arraylist_get(list, 4);
}

arraylist* arraylist_create()
{
    arraylist* list = malloc(sizeof(arraylist));
    void* arr = calloc(sizeof(int), INITIAL_CAPACITY);
    list->data = arr;
    assert(list->data);

    list->length = 0;
    list->capacity = INITIAL_CAPACITY;

    return list;
}

void arraylist_allocate(arraylist* list, unsigned int size)
{
    if (size > list->capacity * 0.6) {
        unsigned int new_capacity = list->capacity;
		while (new_capacity * 0.6 < size)
			new_capacity *= 2;
        
        list->data = realloc(list->data, sizeof(void*) * new_capacity);
        assert(list->data);
        list->capacity = new_capacity;
    }
}

void arraylist_append(arraylist* list, void* item)
{
    arraylist_allocate(list, list->length);
    list->data[list->length++] = item;
}

void* arraylist_get(arraylist* list, unsigned int index)
{
    if (index < 0 || index > list->length) {
        printf("EXCEPTION: Index %d out of bound!", index);
        exit(EXIT_FAILURE);
    }

    return list->data[index];
}

