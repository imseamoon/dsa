#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int xorSum = 0;

    for(int i = 0 ; i < numsSize; i++)
    {
        xorSum ^= nums[i];
    }

    unsigned int lowestBit = xorSum & -(unsigned int)xorSum;

    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int)*2);
    memset(result, 0, sizeof(int) * 2);

    for(int i = 0 ; i< numsSize; i++){
         if ((lowestBit & nums[i]) == 0) {
                result[0] ^= nums[i];
            } else {
                result[1] ^= nums[i];
            }
    }



    return result;
}


int main(int argv, char*argc[])
{
	int array[] = {1, 1, 2, 2, 3 ,3,4, 5};

	int returnSize;

	int *result = singleNumber(array, sizeof(array)/sizeof(array[0]), &returnSize);

	printf("%d, %d", result[0], result[1]);

	return 0;
}





