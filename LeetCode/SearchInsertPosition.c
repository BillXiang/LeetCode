/**
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 -> 2
[1,3,5,6], 2 -> 1
[1,3,5,6], 7 -> 4
[1,3,5,6], 0 -> 0
**/
#include <stdio.h>

static int binarySearch(int* nums, int start, int end, int target){
    if(nums[start]>target){
        return start;
    }
    if(nums[end]<target){
        return end+1;
    }
    int mid = (start+end)>>1;
    if(nums[mid]==target){
        return mid;
    }else if(nums[mid]<target){
        if(mid==start){
            return start+1;
        }
        return binarySearch(nums, mid+1, end, target);
    }else{
        return binarySearch(nums, start, mid-1, target);
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    return binarySearch(nums, 0, numsSize-1, target);
}

void searchInsertMain(void){
    int nums[] = {1, 3, 5, 6};
    //{1, 3, 5};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    printf( "%d\n", searchInsert(nums, numsSize, 4) );
    printf( "%d\n", searchInsert(nums, numsSize, 5) );
    printf( "%d\n", searchInsert(nums, numsSize, 2) );
    printf( "%d\n", searchInsert(nums, numsSize, 7) );
    printf( "%d\n", searchInsert(nums, numsSize, 0) );
}
