/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
**/
#include <stdio.h>

static int binarySearch(int* nums, int start, int end, int target){
    if(nums[start]==target){
        return start;
    }
    if(nums[end]==target){
        return end;
    }
    int mid = (start+end)>>1;
    if(mid==start){
        return -1;
    }
    if(nums[mid]==target){
        return mid;
    }else if(nums[mid]<target){
        return binarySearch(nums, mid+1, end, target);
    }else{
        return binarySearch(nums, start, mid-1, target);
    }
}

int findRoateIndexOld(int* nums, int start, int end){
    int roateIndex = -1;
    int i = 0;
    for(i=start; i<end; i++){
        if(nums[i+1]<nums[i]){
            roateIndex = i;
            break;
        }
    }
    return roateIndex;
}

int findRoateIndex(int* nums, int start, int end){
    if(start+1==end && nums[start]>nums[end]){
        return start;
    }
    int mid = (start+end)>>1;
    if(nums[start]>nums[mid]){
        return findRoateIndex(nums, start, mid);
    }else if(nums[mid]>nums[end]){
        return findRoateIndex(nums, mid, end);
    }else{
        return -1;
    }
}

int search(int* nums, int numsSize, int target) {

    int roateIndex = findRoateIndex(nums, 0, numsSize-1);

    if(roateIndex==-1){
        return binarySearch(nums, 0, numsSize-1, target);
    }
    int result = binarySearch(nums, 0, roateIndex, target);
    if(result==-1){
        result = binarySearch(nums, roateIndex+1, numsSize-1, target);
    }
    return result;
}

void searchMain(void){
    int nums[] = //{4, 5, 6, 7, 1, 2, 3, 4};
    //{1, 2, 3};
    //{1};
    {1,3,1,1,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    printf("%d\n", search(nums, numsSize, 0));
    printf("%d\n", search(nums, numsSize, 1));
    printf("%d\n", search(nums, numsSize, 2));
    printf("%d\n", search(nums, numsSize, 3));
    printf("%d\n", search(nums, numsSize, 4));
    printf("%d\n", search(nums, numsSize, 5));
    printf("%d\n", search(nums, numsSize, 6));
    printf("%d\n", search(nums, numsSize, 7));
}
