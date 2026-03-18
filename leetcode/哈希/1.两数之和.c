#include <stdio.h>
#include <stdlib.h>
int main()
{
    return 0;
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int symbol = 0;
    int *arr = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                arr[0] = i;
                arr[1] = j;
                symbol = 1;
                break;
            }
        }
        if (symbol == 1)
        {
            *returnSize = 2;
            break;
        }
    }
    return arr;
}