#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    if(nums==NULL || numsSize<2)
        return -1;

    int *result = (int *)malloc(2*sizeof(int));
    int *index = (int *)malloc(numsSize*sizeof(int));
    int i = 0;
    for(i=0; i<numsSize; i++)
    {
        index[i] = i+1;
    }
    result[0] = -1;
    result[1] = -1;

    my_index_qsort(nums, index, 0, numsSize-1);
    int start = 0;
    int end = numsSize-1;
    int dif = 0;
    while(start<end)
    {
        dif = target-nums[end];
        if(dif==nums[start])
            break;
        else if(dif>nums[start])
            start++;
        else
            end--;
    }
    if(start<end)
    {
        result[0] = index[start];
        result[1] = index[end];
        if(result[0]>result[1])
            my_swap(result, 0, 1);
    }
    free(index);
    return result;
}

int array[] = {9,4,5,8,7,1,0,3};
//获取数组长度
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
//测试
void twoSumMain(void)
{
    int len;
    int i;
    GET_ARRAY_LEN(array, len);
    //my_qsort(array, 0, len-1);
    for(i=0; i<len; i++)
        printf("%d ", array[i]);
    int *result = twoSum(array, len, 15);
    printf("\n%d %d\n", result[0], result[1]);
    free(result);
    for(i=0; i<len; i++)
        printf("%d ", array[i]);
    return 0;
}
