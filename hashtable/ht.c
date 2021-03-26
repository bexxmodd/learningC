#include <stdio.h>

// Hash table entry (slot may be filled or empty).
typedef struct {
    /* data */
    char* key;
    void* value;
} ht_entry;

// Hash table structure: create with ht_create, free with ht_destroy.
typedef struct {
    ht_entry* entries; // hash slots
    size_t capacity; // size of _entries array
    size_t length; // number of items in hash table
} ht;

#define INITIAL_CAPACITY 16 // must not be zero

ht* ht_create(void)
{
    // Allocate space for hash table struct.
    ht* table = malloc(sizeof(int));
    if (table == NULL)
        return NULL;
    table->length = 0;
    table->capacity = INITIAL_CAPACITY;

    // Allocate (zero'd) space for entry buckets;
    table->entries = calloc(table-> capacity, sizeof(ht_entry));
    if (table->entries == NULL) {
        free(table); // error, free table before we return
        return NULL;
    }
    return table;
}

void ht_destroy(ht* table)
{
    // first free allocated keys
    for (size_t i = 0; i< table->capacity; i++)
        if (table->entries[i].key != NULL)
            free(table->entries[i].key);
    
    // Finally free entries array and table itself
    free(table->entries);
    free(table);
}
