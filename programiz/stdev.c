#include <stdio.h>
#include <math.h>

float mean(int *nums, int length);
float stdev(int *nums, int length);
float variance(int *nums, int length);

int main()
{
    int A[] = {46, 69, 32, 60, 52, 41};
    int s = sizeof(A) / sizeof(A[0]);
    printf("mean = %.2f\n", mean(A, s));
    printf("Variance = %.2f\n", variance(A, s));
    printf("Standard Deviation = %.2f\n", stdev(A, s));
    return 0;
}

/* computes the mean of an array of integers */
float mean(int *nums, int length)
{
    int count, total = 0;
    for (count = 0; count < length; count++) {
        total += *nums++;
    }
    return total / count;
}

/* calculates the variance of an array */
float variance(int *nums, int length)
{
    int i;
    float m, sumOfSqr, var;
    m = mean(nums, length);
    int squared[length];

    for (i = 0; i < length; i++) {
        squared[i] = (nums[i] - m) * (nums[i] - m);
        sumOfSqr += squared[i];
    }

    return sumOfSqr / (length - 1);
}

/* calculates the standard deviation of an array */
float stdev(int *nums, int length)
{
    return sqrt(variance(nums, length));
}