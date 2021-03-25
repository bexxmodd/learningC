#include <stdio.h>
#include <stdlib.h>

// In recursive function, first check the termination condition.

int main()
{
    FILE* text = fopen("text.txt", "r");
    char line[1000];
    if (!text) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    // while (fgets(line, 1000, text) != NULL)
    //     puts(line);

    char c = fgetc(text);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(text);
    }

    fclose(text);
    
    return 0;
}