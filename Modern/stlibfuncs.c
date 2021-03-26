#include <stdio.h>
#include <stdlib.h>

// In recursive function, first check the termination condition.

int main()
{
    FILE* text = fopen("text.txt", "a+");
    char line[1000];
    if (!text) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    fputs("Sk8 till death!\n", text);
    fclose(text);
    // while (fgets(line, 1000, text) != NULL)
    //     puts(line);

    text = fopen("text.txt", "a+");
    if (!text) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    char c = fgetc(text);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(text);
    }

    fclose(text);
    
    return 0;
}