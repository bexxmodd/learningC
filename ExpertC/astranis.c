#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup_every_other_char(const char *s);

int main()
{
        char text[] = "house";
        char *dest;;
        printf("Result: %s\n",  strdup_every_other_char(text));
        return 0;
}

char *strdup_every_other_char(const char *s)
{
        int i, k, len = strlen(s) / 2.0 + 0.5f;
        char *dest = malloc(sizeof(char) * (len + 1));

        for (i = 1, k = 0; *s != '\0'; i++, s++)
                if (i % 2 != 0)
                        dest[k++]= *s;
        dest[k] = '\0';

        return dest;
}
