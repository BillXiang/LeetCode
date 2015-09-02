#include <stdio.h>
#include <stdlib.h>

int myPartition(int* nums, int start, int end){
    int p = start;
    start++;
    while(start<end){
        while(nums[start]<=nums[p] && start<end)
            start++;
        while(nums[end]>nums[p] && end>start)
            end--;
        if(end>start){
            nums[start] = nums[start]+nums[end];
            nums[end] = nums[start]-nums[end];
            nums[start] = nums[start]-nums[end];
        }
    }

    if(nums[start]>nums[p]){
        start--;
    }
    if(start>p){
        nums[start] = nums[start]+nums[p];
        nums[p] = nums[start]-nums[p];
        nums[start] = nums[start]-nums[p];
    }
    return start;
}

void myQsort(int* nums, int start, int end){
    if(start==end-1){
        if(nums[start]>nums[end]){
            nums[start] = nums[start]+nums[end];
            nums[end] = nums[start]-nums[end];
            nums[start] = nums[start]-nums[end];
        }
        return;
    }
    int p = myPartition(nums, start, end);
    if(p>start+1)
        myQsort(nums, start, p-1);
    if(p<end-1)
        myQsort(nums, p+1, end);
}

void towSum(int* nums, int numsSize, int start, int** result, int* returnSize){//nums从小到大排序
    int i = start+1;
    int j = numsSize-1;
    int tmp = 0;
    while(i<j){
        tmp = nums[i]+nums[j];
        if(tmp<-nums[start]){
            //do{
                i++;
            //}
            //while(nums[i+1]==nums[i] && i<j);
        }else if(tmp>-nums[start]){
            //do{
               j--;
            //}while(nums[j-1]==nums[j] && i<j);
        }else{
            //得到一组结果
            result[*returnSize] = (int *)malloc(3*sizeof(int));
            result[*returnSize][0]= nums[start];
            result[*returnSize][1] = nums[i];
            result[*returnSize][2] = nums[j];

            (*returnSize)++;

            do{
                i++;
            }
            while(i<j && nums[i]==nums[i-1]);
            do{
               j--;
            }while(i<j && nums[j]==nums[j+1]);

        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    myQsort(nums, 0, numsSize-1);
    int maxReturnSize = numsSize*numsSize/4;
    int** result = (int **)malloc(maxReturnSize*sizeof(int *));
    int i=0;

    *returnSize = 0;

    for(i=0; i<numsSize-2 && nums[i]<=0; ){
        towSum(nums, numsSize, i, result, returnSize);
        do{
            i++;
        }
        while(nums[i]==nums[i-1] && i<numsSize-2);
    }
    return result;
}

#define GET_ARRAY_LEN(array, len) {len = sizeof(array)/sizeof(array[0]);}
void threeSumMain(void){
    int len = 0;
//    int array[] = {-1, 0, 1, 2, -1, -4};
    //int array[] = {1,3,2,5,6,3,8,4,6,5,9,0,21};
    int array[] = //{0, 0, 0};
    //{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //{-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
    //{-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    GET_ARRAY_LEN(array, len);
    myQsort(array, 0, len-1);
    while(len){
        printf("%d\n", array[len-1]);
        len--;
    }

    GET_ARRAY_LEN(array, len);
    int returnSize = 0;
    int** result = threeSum(array, len, &returnSize);
    int i = 0;
    for(i=0; i<returnSize; i++){
        printf("%d %d %d\n", result[i][0],
                result[i][1],
                result[i][2]);
        free(result[i]);
    }
    free(result);
}
