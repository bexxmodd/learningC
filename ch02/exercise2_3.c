#include <stdio.h>
#include <string.h>
#include <math.h>

int hexTable(char c);
int hexToDecimal(char s[]);

int main()
{
    int decimal;
    char hex[] = "x2ab";
    printf("%s = %d\n", hex, hexToDecimal(hex));
    char hex1[] = "x1ff";
    printf("%s = %d\n", hex1, hexToDecimal(hex1));
    char hex2[] = "b";
    printf("%s = %d\n", hex2, hexToDecimal(hex2));
    char hex3[] = "13b";
    printf("%s = %d\n", hex3, hexToDecimal(hex3));

    return -1;
}

/* first 15 digits of fex base 16 number */
int hexTable(char c)
{
    if (c >= '0' && c < '9')
        return c - 48;
    else if (c >= 'a' && c <= 'f')
        return c - 87;
    else return -1;
}

int hexToDecimal(char s[])
{
    int size = strlen(s);
    int power = strlen(s) - 1;
    int dec = 0;
    int start = 0;

    // If a given hex number starts 'x' move 
    // the starting pointer to the second char
    if (s[0] == 'x') {
        size--;
        power--;
        start++;
    }

    // if the value is under 16
    if (size < 2) return hexTable(s[0]);

    for (int i=start; i < strlen(s); i++){
        dec += pow(16, power--) * hexTable(s[i]);
    }

    return dec;
}