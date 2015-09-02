#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int threeSumClosestPartition(int* nums, int start, int end){
    while(start<end){
        while(nums[start]<=nums[end] && start<end){
            start++;
        }
        if(start<end){//交换
            nums[start] = nums[start]+nums[end];
            nums[end] = nums[start]-nums[end];
            nums[start] = nums[start]-nums[end];
        }
        while(nums[end]>nums[start] && start<end){
            end--;
        }
        if(start<end){
            nums[start] = nums[start]+nums[end];
            nums[end] = nums[start]-nums[end];
            nums[start] = nums[start]-nums[end];
        }
    }
    return start;
}

void threeSumClosestQSort(int* nums, int start, int end){
    int p = threeSumClosestPartition(nums, start, end);
    if(p>start+1){
        threeSumClosestQSort(nums, start, p-1);
    }
    if(p<end-1){
        threeSumClosestQSort(nums, p+1, end);
    }
}

int twoSumClosestDif(int* nums, int numsSize, int start, int target){
    int dif = 0;
    int minDif = INT_MAX;
    int i = start;
    int j = numsSize-1;
    do{
        dif = nums[i]+nums[j]-target;
        if(dif>0){
            j--;
        }else if(dif<0){
            i++;
        }else{
            return 0;
        }
        if(abs(dif)<abs(minDif)){
            minDif = dif;
        }
    }while(i<j);
    return minDif;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    if(nums==NULL || numsSize<3){
        return 0;
    }
    threeSumClosestQSort(nums, 0, numsSize-1);
    int dif = 0;
    int minDif = INT_MAX;
    int i = 0;
    for(i=1; i<numsSize-1;){
        dif = twoSumClosestDif(nums, numsSize, i, target-nums[i-1]);
        if(dif==0){
            return target;
        }else if(abs(dif)<abs(minDif)){
            minDif = dif;
        }
        //do{
            i++;
        //}while(nums[i-1]==nums[i-2] && i<numsSize-1);
    }
    return target+minDif;
}
#define GET_ARRAY_LEN(array, len) {len = sizeof(array)/sizeof(array[0]);}
void threeSumClosestMain(void){
    int len = 0;
    //    int array[] = {-1, 0, 1, 2, -1, -4};
    //int array[] = {1,3,2,5,6,3,8,4,6,5,9,0,21};
    int array[] = //{0, 0, 0};
    //{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //{-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
    //{-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    //{-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //{-1, 2, 1, -4};
    {1,1,1,0};
    GET_ARRAY_LEN(array, len);

    printf("%d\n", threeSumClosest(array, len, 100));

    //threeSumClosestQSort(array, 0, len-1);
//    while(len){
//        printf("%d\n", array[len-1]);
//        len--;
//    }
}
