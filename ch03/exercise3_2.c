#include <stdio.h>

void escape(char s[]);

int main()
{
    char s[] = "hello\n what is \t going \t on";
    escape(s);
    // printf("%s", escape(*s));
    return -1;
}

void escape(char s[])
{
    char t[sizeof(s)];
    int i;
    for (i = 0; i < sizeof(s); i++) {
        switch (s[i]) {
            case '\n':
                t[i] = 'N';
                break;
            case '\t':
                t[i] = 'T';
                break;
            default:
                t[i] = s[i];
                break;
        }
    }
    printf("%s", t);
}