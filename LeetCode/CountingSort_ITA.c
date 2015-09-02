#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void countingSort(struct ListNode** lists, int listsSize){
    int counting[100] = {0};
    int* result = (int*)malloc(listsSize*sizeof(int));
    int i = 0;
    for(i=0; i<100; i++){
        counting[i]=0;
    }
    for(i=0; i<listsSize; i++){
        counting[lists[i]->val]++;
    }
    int count = 0;
    for(i=0; i<100; i++){
        count += counting[i];
        counting[i] = count;
    }
    for(i=0; i<listsSize; i++){
        result[counting[lists[i]->val]-1] = lists[i]->val;
        counting[lists[i]->val] = counting[lists[i]->val]-1;
    }
    for(i=0; i<listsSize; i++){
        //printf("%d\n", result[i]);
    }
}

void countingSortMain(void){
    countingSort(lists, 10000);
}
