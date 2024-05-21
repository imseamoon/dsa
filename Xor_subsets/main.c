#include <stdio.h>
#include <stdlib.h>

int subsetXORSum(int *nums, int numsSize)
{
    int total = 0;

    for (int i = 0; i < numsSize; i++)
    {
        total |= nums[i];
    }

    return total * (1 << (numsSize - 1));
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = subsetXORSum(nums, numsSize);

    printf("%d\n", result);

    return 0;
}