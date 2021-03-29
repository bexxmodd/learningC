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

    dict hello = {"Hello", 1};
    dict world = {"world", 1};
    dict once = {"once", 1};
    dict again = {"again", 1};
    dict arr[] = {hello, world, once, again};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    for (i = 1; i < argc; i++) {
        for (j = 0; j < size; j++) {
            if (strcmp(argv[i], arr[j].word) == 0)
                arr[j].count++;
        }
    }
    for (i = 0; i < 4; i++)
        printf("word: %s count: %d\n", arr[i].word, arr[i].count);
    
    return 0;
}

