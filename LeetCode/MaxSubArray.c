/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
**/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//只要大于0就往上加
int maxSubArray(int* nums, int numsSize) {
    if(nums==NULL || numsSize==0){
        return 0;
    }
    int maxSum = INT_MIN;
    int curSum = 0;
    int i = 0;
    for(i=0; i<numsSize; i++){
        if(curSum>0){
            curSum += nums[i];
        }else{
            curSum = nums[i];
        }
        if(curSum>maxSum){
            maxSum = curSum;
        }
    }
    return maxSum;
}
#define GET_ARRAY_LEN(array, len) {len = sizeof(array)/sizeof(array[0]);}
void maxSubArrayMain(void){
    int nums[] = //{0, -2, 3, 5, -1, 2};
    //{-9,-2,-3,-5,-3};
    {-2,1,-3,4,-1,2,1,-5,4};
    int len = 0;
    GET_ARRAY_LEN(nums, len);
    printf("%d\n", maxSubArray(nums, len));
}
