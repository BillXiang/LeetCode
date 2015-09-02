#include <stdio.h>
//需要hash
//int longestConsecutive(int* nums, int numsSize) {
//    int i = 0;
//    int max = 0;
//    int min = 0;
//    int maxLen = 0;
//    int len = 0;
//
//    for(i=1; i<numsSize; i++){
//        if(nums[i]==nums[max]+1){
//            max = i;
//        }else if(nums[i]==nums[min]-1){
//            min = i;
//        }else{
//            len = nums[max]-nums[min]+1;
//            if(maxLen<len){
//                maxLen = len;
//            }
//            max = i;
//            min = i;
//        }
//    }
//
//    return maxLen;
//}

void longestConsecutiveMain(void){
    int nums[] = {100, 4, 200, 1, 3, 2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
//    printf("%d\n", longestConsecutive(nums, numsSize));
}
