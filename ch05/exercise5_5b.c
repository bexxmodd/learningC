#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char *s)
{
    double val, power;
    int sign;

    for (; isspace(*s); *s++) // skip white space
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        *s++;
    for (val = 0.0; isdigit(*s); *s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        *s++;
    for (power = 1.0; isdigit(*s); *s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10;
    }
    return sign * val / power;
}

/* atoi: convert string s to integer using atof */
int atoi(char *s)
{
    double atof(char *s);
    return (int) atof(s);
}

int main()
{
    char line[] = "-32.57341";
    float df = atof(line);
    int dd = atoi(line);
    printf("float value of a %s is %4.4f and integer %d\n", line, df, dd);
    return 0;
}