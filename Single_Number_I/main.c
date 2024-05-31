#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize)
{
    int xorSum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        xorSum ^= nums[i];
    }

    return xorSum;
}

int main(int argv, char *argc[])
{

    int array[] = {1, 1, 2, 2, 3, 3, 4};

    int ans = singleNumber(array, sizeof(array) / sizeof(array[0]));
    printf("%d", ans);
    return 0;
}