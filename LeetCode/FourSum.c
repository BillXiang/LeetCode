#include <stdio.h>
#include <stdlib.h>

struct quadruplet{
    int nums[4];
    struct quadruplet* next;
};

int fourSumPartition(int* nums, int start, int end){
    int i = start;
    int j = end;
    while(i<j){
        while(nums[i]<=nums[j] && i<j){
            i++;
        }
        if(i<j){
            nums[i] = nums[i]+nums[j];
            nums[j] = nums[i]-nums[j];
            nums[i] = nums[i]-nums[j];
        }
        while(nums[j]>nums[i] && j>i){
            j--;
        }
        if(i<j){
            nums[i] = nums[i]+nums[j];
            nums[j] = nums[i]-nums[j];
            nums[i] = nums[i]-nums[j];
        }
    }
    return i;
}

void fourSumQsort(int* nums, int start, int end){
    int p = fourSumPartition(nums, start, end);
    if(p>start+1){
        fourSumQsort(nums, start, p-1);
    }
    if(p<end-1){
        fourSumQsort(nums, p+1, end);
    }
}

void fourSumTwoSum(int* nums, int numsSize, int start, int target,
            int indexA, int indexB,
            struct quadruplet** quadruplets, int* returnSize){
    int i = start;
    int j = numsSize-1;
    int sum = 0;
    struct quadruplet* tmp = NULL;
    while(i<j){
        sum = nums[i]+nums[j];
        if(sum==target){
            tmp = (struct quadruplet*)malloc(sizeof(struct quadruplet));
            tmp->nums[0] = nums[indexA];
            tmp->nums[1] = nums[indexB];
            tmp->nums[2] = nums[i];
            tmp->nums[3] = nums[j];
            (*quadruplets)->next = tmp;
            *quadruplets = tmp;
//            *(quadruplets+*returnSize) = (int *)malloc(4*sizeof(int));
//            *(*(quadruplets+*returnSize)+0) =
//            *(*(quadruplets+*returnSize)+1) = nums[indexB];
//            *(*(quadruplets+*returnSize)+2) = nums[i];
//            *(*(quadruplets+*returnSize)+3) = nums[j];
            *returnSize  = *returnSize+1;
            do{
                i++;
            }while(i<j && nums[i]==nums[i-1]);
            do{
                j--;
            }while(i<j && nums[j]==nums[j+1]);
        }else if(sum<target){
            i++;
        }else{
            j--;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(nums==NULL || numsSize<4){
        *returnSize = 0;
        return NULL;
    }
//    int size = numsSize*(numsSize-1)*(numsSize-2)*(numsSize-3);
//    int** quadruplets = (int **)malloc(size*sizeof(int *));
//    if(quadruplets==NULL){
//        printf("OOM\n");
//        return NULL;
//    }
    struct quadruplet head;
    struct quadruplet* pHead = &head;
    fourSumQsort(nums, 0, numsSize-1);
    *returnSize = 0;
    int i = 0;
    int j = 0;
    for(i=0; i<numsSize-3;){
        for(j=i+1; j<numsSize-2;){
            fourSumTwoSum(nums, numsSize, j+1, target-nums[i]-nums[j], i, j, &pHead, returnSize);
            do{
                j++;
            }while(j<numsSize-2 && nums[j]==nums[j-1]);
        }
        do{
            i++;
        }while(i<numsSize-3 && nums[i]==nums[i-1]);
    }
    int** quadruplets = (int **)malloc(*returnSize*sizeof(int *));

    struct quadruplet* pre = NULL;
    pHead = head.next;
    for(i=0; i<*returnSize; i++){
        *(quadruplets+i) = (int *)malloc(4*sizeof(int));
        *(*(quadruplets+i)+0) = pHead->nums[0];
        *(*(quadruplets+i)+1) = pHead->nums[1];
        *(*(quadruplets+i)+2) = pHead->nums[2];
        *(*(quadruplets+i)+3) = pHead->nums[3];
        pre = pHead;
        pHead = pHead->next;
        free(pre);
    }
    return quadruplets;
}
#define GET_ARRAY_LEN(array, len) {len = sizeof(array)/sizeof(array[0]);}
void fourSumMain(void){
    int len = 0;
    int array[] = //{0, 0, 0};
    //{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //{-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
    {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    //{-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //{-497,-494,-484,-477,-453,-453,-444,-442,-428,-420,-401,-393,-392,-381,-357,-357,-327,-323,-306,-285,-284,-263,-262,-254,-243,-234,-208,-170,-166,-162,-158,-136,-133,-130,-119,-114,-101,-100,-86,-66,-65,-6,1,3,4,11,69,77,78,107,108,108,121,123,136,137,151,153,155,166,170,175,179,211,230,251,255,266,288,306,308,310,314,321,322,331,333,334,347,349,356,357,360,361,361,367,375,378,387,387,408,414,421,435,439,440,441,470,492};
    GET_ARRAY_LEN(array, len);
    //fourSumQsort(array, 0, len-1);
    int returnSize = 0;
    int** result = fourSum(array, len, 4, &returnSize);
    int i = 0;
    for(i=0; i<returnSize; i++){
        printf("%d %d %d %d\n", *(*(result+i)+0), *(*(result+i)+1), *(*(result+i)+2), *(*(result+i)+3));
    }

    while(len){
        printf("%d\n", array[len-1]);
        len--;
    }
}
