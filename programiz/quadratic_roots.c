#include <stdio.h>
#include <math.h>

void quadraticroot(double a, double b, double c, double *roots);

int main()
{
    double a, b, c;
    double roots[2];
    printf("Enter coeficients a, b, c of the quadratic equation:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    quadraticroot(a, b, c, roots);
    printf("Roots are %lf and %lf", roots[0], roots[1]);
    
    return 0;
}

void quadraticroot(double a, double b, double c, double *roots)
{
    double discriminant, root1, root2, root3;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        *roots++ = (-b + sqrt(discriminant)) / (2 * a);
        *roots = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        *roots++ = -b / (2*a);
        *roots = -b / (2*a);
    } else {
        *roots++ = -b / (2*a);
        *roots = sqrt(-discriminant) / (2*a);
    }
}