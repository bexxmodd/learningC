#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    size_t const len = strlen(argv[1]); // define the size of an argument word
    size_t const len2 = strlen(argv[2]);

    printf("length1: %ld\n", len);
    printf("length2: %ld\n", len2);

    char name[len+1];
    char status[len2+1];

    memcpy(name, argv[1], len); // copy the second argument from terminal into a string array
    memcpy(status, argv[2], len); // copy the third argument from terminal into a string array

    name[len] = '\0';
    name[len2] = '\0';
    printf("Name: %s\n", name);
    printf("Status: %s\n", status);

    if (strcmp(argv[1], argv[2]) > 0) // compare two strings lexicographically
        printf("%s wins!\n", argv[1]);
    else
        printf("%s wins!\n", argv[2]);

    return 0;
}