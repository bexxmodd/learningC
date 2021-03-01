#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "beka likes C programming";
    char s2[] = "youknow";
    squeeze(s1, s2);
    printf("%s\n", s1);

    return -1;
}

/* removes chars from s1 which are present in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                i++;
        s1[k++] = s1[i];
    }
    s1[k] = '\0';
}