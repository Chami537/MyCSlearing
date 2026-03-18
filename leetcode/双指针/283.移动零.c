void moveZeroes(int *nums, int numsSize)
{
    int *record = (int *)malloc(numsSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            // get the index of non-zero numbers
            record[count] = i;
            count++;
        }
    }
    int k = sizeof(record) / sizeof(int);
    for (int j = 0; j < count; j++)
    {
        nums[j] = nums[record[j]];
    }
    for (int k = 0; k < numsSize - count; k++)
    {
        nums[k + count] = 0;
    }
}
// the way of two pointers
void moveZeroes(int *nums, int numsSize)
{
    int findzero = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[findzero++] = nums[i];
        }
    }
    for (int j = findzero; j < numsSize - findzero; j++)
    {
        nums[j] = 0;
    }
}
