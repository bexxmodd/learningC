#include <stdio.h>

float maxf(float *nums);
int maxi(int *nums);

int main()
{
    float numbers[] = {3.1, 4.1, 5.0, 15.3, -2.1, 6.2, 0.0, -2.2};
    int nums[] = {3, 4, -2, 5, -6, 11, 13};
    float m = maxf(numbers);
    printf("max float is %.2f\n", m);
    int m1 = maxi(nums);
    printf("max int is %d\n", m1);
    return 0;
}

float maxf(float *nums)
{
    float m = *nums++;
    for (; *nums != '\0'; *nums++) {
        if (*nums > m)
            m = *nums;
    }
    return m;
}

int maxi(int *nums)
{
    int m = *nums++;
    for (; *nums != '\0'; *nums++) {
        if (*nums > m)
            m = *nums;
    }
    return m;
}

