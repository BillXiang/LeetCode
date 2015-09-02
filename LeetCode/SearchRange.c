/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
**/
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarySearch(int* nums, int start, int end, int target){
    if(nums[start]==target){
        return start;
    }
    if(nums[end]==target){
        return end;
    }
    if(end-start<2){
        return -1;
    }
    int mid = (start+end)>>1;
    if(nums[mid]==target){
        return mid;
    }
    int result = -1;
    if(mid-1>start){
        result = binarySearch(nums, start, mid-1, target);
    }
    if(result==-1 && mid+1<end){
        result = binarySearch(nums, mid+1, end, target);
    }
    return result;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int index = binarySearch(nums, 0, numsSize-1, target);
    int* result = NULL;
    *returnSize = 2;
    result = (int*)malloc(2*sizeof(int));
    if(index==-1){
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    int start = index-1;
    int end = index+1;
    while(start>=0 && nums[start]==target){
        start--;
    }
    while(end<numsSize && nums[end]==target){
        end++;
    }
    result[0] = start+1;
    result[1] = end-1;
    return result;
}

void searchRangeMain(void){
    int nums[] = {7, 7, 7, 8, 8, 10};
    //{1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize = 0;
    int* result = searchRange(nums, numsSize, 7, &returnSize);
    for(;returnSize>0; returnSize--){
        printf("%d\n", result[returnSize-1]);
    }
    free(result);
}
