#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* word;
    int count;
} dict;

int main(int argc, char** argv)
{
    int i, j;

    dict* arr[100];
    dict a = {argv[0], 1};
    arr[0] = &a;
    size_t size = sizeof(arr) / sizeof(arr[0]);

    for (i = 1; i < argc; i++) {
        for (j = 0; j < size; j++) {
            if (strcmp(argv[i], arr[j]->word) == 0) {
                printf("found");
            } else {
                arr[j] = (dict*) malloc(sizeof(dict));
                arr[j]->word = argv[i];
                arr[j]->count = 1;
            }
        }

    }
    for (i = 0; i < 5; i++)
    printf("word: %s count: %d\n", arr[i]->word, arr[i]->count);
    
    return 0;
}

