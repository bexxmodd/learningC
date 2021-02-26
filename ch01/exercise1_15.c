#include <stdio.h>

double fahrToCelc(int fahr);

/* count lines, words, and characters in input */
int main()
{
    double c;
    printf("Enter temprature in celcius: ");
    scanf("%lf", &c);
    printf("%f fahr in celcius is: %2.2lf", c, fahrToCelc(c));
}

double fahrToCelc(int fahr)
{
    return 5.0 * (fahr-32) / 9;
}