#include <stdio.h>
#include <math.h>

int binatyToDecimal(char *b, int size);
int sizes(char *line);

int main()
{
    char bin[100];
    printf("Enter the binary number:\n");
    scanf("%s", bin);
    int size = sizes(bin);
    printf("Size = %d\n", size);
    printf("Decimal: %d\n", binatyToDecimal(bin, size));
    return 0;
}

int binatyToDecimal(char *b, int size)
{
    int power, x;
    float result = 0;
    for (power = size - 1; power > -1; power--) {
        int x = (*b++) - '0';
        result += pow(2, power) * x;
    }
    return (int) result;
}

int sizes(char *line)
{
    int size = 0;
    for (; *line != '\0'; *line++)
        size++;
        printf("sizes: %d\t", *line);
    return size;
}