#include <stdio.h>

typedef struct {
    /* data */
    char* key;
    int value;
} dict;

/* linear search for a item in adict structure */
dict* linear_search(dict* items, size_t size, const char* key)
{
    size_t i;

    for (i = 0; i < size; i++) {
        if (strcmp(items[i].key, key) == 0)
            return &items[i];
    }
    return NULL;
}

/* compare two dict structs */
int cmp(const void* a, const void* b)
{
    dict* item_a = (dict*) a;
    dict* item_b = (dict*) b;
    return strcmp(item_a->key, item_b->key);
}

dict* binary_search(dict* items, size_t size, const char* key)
{
    size_t low = 0;
    size_t high = size;
    while (low < high) {
        size_t mid = (low + high) / 2;
        int c = strcmp(items[mid].key, key);
        if (c == 0)
            return &items[mid];
        if (c < 0)
            low = mid + 1;
        else
            high = mid;
    }

    if (low < size && strcmp(items[low].key, key) == 0)
        return &items[low];
    return NULL;
}
