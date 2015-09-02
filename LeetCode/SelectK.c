#include <stdio.h>
#include <stdlib.h>
static int deep = 0;
//选择第K大的数
int selectKpartition(int* nums, int start, int end){
    int i = start;
    int j = end;
    while(i<j-1){
        while(nums[i]<=nums[j] && i<j-1){
            i++;
        }
        if(nums[i]>nums[j]){
            nums[i] = nums[i]^nums[j];
            nums[j] = nums[i]^nums[j];
            nums[i] = nums[i]^nums[j];
        }
        while(nums[i]<nums[j] && i<j-1){
            j--;
        }
        if(nums[i]<=nums[j]){
            nums[i] = nums[i]^nums[j];
            nums[j] = nums[i]^nums[j];
            nums[i] = nums[i]^nums[j];
        }

    }
    return i;
}

int selectKrecursion(int* nums, int start, int end, int k){
    deep++;
    int p = selectKpartition(nums, start, end);
    if(p-start==k-1){
        return p;
    }else if(p-start>k-1){
        return selectKrecursion(nums, start, p, k);
    }else{
        return selectKrecursion(nums, p+1, end, k-p-1);
    }
}

int selectK(int* nums, int size, int k){
    if(nums==NULL || k>size){
        return -1;
    }

    int p = selectKpartition(nums, 0, size-1);
    if(p==k-1){
        return p;
    }else if(p>k-1){
        return selectKrecursion(nums, 0, p-1, k);
    }else{
        return selectKrecursion(nums, p+1, size-1, k-p-1);
    }
}

void selectKmain(void){
    int nums[1000] = {0};
    int i = 0;
    for(i=1000; i>0; i--){
        nums[1000-i] = i;
    }
    printf("%d\n", selectK(nums, 1000, 98));
}
