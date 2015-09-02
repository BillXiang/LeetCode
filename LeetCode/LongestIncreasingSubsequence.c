#include <stdio.h>
//最长递增子序列
int LIS(int* nums, int numsSize){
    int lisi[numsSize];
    lisi[0] = 1;
    int i = 0;
    int j = 0;
    int maxLen = 1;
    int maxIndex = 0;
    int newLen = 0;
    for(i=1; i<numsSize; i++){
        for(j=maxIndex; j>=0; j--){
            if(nums[j]<nums[i]){
                newLen = lisi[j]+1;
                if(maxLen<=newLen){
                    maxLen = newLen;
                    maxIndex = i;
                }
            }
        }
        lisi[i] = maxLen;
    }
    return lisi[numsSize-1];
}

void LISmain(void){
    int nums[] = //{1,2,3,4,5,5,3,2,5,6,7,4};
    //{35, 36, 39, 3, 15, 27, 6, 42};
    //{5, 4, 3, 2, 1};
    {1, -1, 2, -2, 0, 1, 1};
    int len = sizeof(nums)/sizeof(nums[0]);
    printf("%d\n", LIS(nums, len));
}
