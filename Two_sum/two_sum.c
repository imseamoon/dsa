#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}

int main(int argv[], char *argc)
{
    int nums[] = {2, 11, 15, 7};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);
    if (result != NULL)
    {
        printf("[%d, %d]\n", result[0], result[1]);
    }
    else
    {
        printf("No solution\n");
    }
    return 0;
}