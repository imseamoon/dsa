#include <stdio.h>
#include <stdlib.h>

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 1 << numsSize;

    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));

    int **result = (int **)malloc(*returnSize * sizeof(int *));

    for (int i = 0; i < *returnSize; i++)
    {
        int subsetSize = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (i & (1 << j))
            {
                subsetSize++;
            }
        }

        (*returnColumnSizes)[i] = subsetSize;
        result[i] = (int *)malloc(subsetSize * sizeof(int));

        int index = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (i & (1 << j))
            {
                result[i][index++] = nums[j];
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }

    return 0;
}