#include <stdio.h>

int main()
{
    int B[2][3] = {
        {8, 2, 4},
        {7, 9, 3}
    };
    int i;

    printf("%ld\n", B);
    printf("%ld\n", B+1);

    printf("%ld\n", *B);
    printf("%ld\n", *B+1);

    printf("%ld\n", *B[0]);
    printf("%ld\n", *B[1]);

    // B[i][j] = *(B[i] * j) = *(*(B+i)+j)

    printf("%ld\n", *(B+1)+2);
    printf("%ld\n", *(*B+1));

    // declaring pointer to 1D array of 3 integers
    int (*p)[3] = B;
    for (i = 0; i < 2; i++)
        printf("%ld\t", p[i][1]);

}