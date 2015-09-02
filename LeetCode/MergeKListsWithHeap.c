#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "data.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//
struct HeapNode{
    struct ListNode* listNode;
    int listsIndex;
};

//调整最小堆
void MIN_HEAP(struct HeapNode* minHeap, int index){
    struct ListNode* tmpListNode = NULL;
    int tmpListsIndex = 0;
    int parent = index>>1;
    while(index){//此处也可以用递归。用循环更高效
        //比父节点小，交换
        if(minHeap[index].listNode->val < minHeap[index>>1].listNode->val){
            tmpListNode = minHeap[index].listNode;
            tmpListsIndex = minHeap[index].listsIndex;

            minHeap[index].listNode = minHeap[parent].listNode;
            minHeap[index].listsIndex = minHeap[parent].listsIndex;

            minHeap[parent].listNode = tmpListNode;
            minHeap[parent].listsIndex = tmpListsIndex;

            index = parent;
            parent = index>>1;
        }else{
            return;
        }
    }
}

void INSERT_MIN_HEAP(struct HeapNode* minHeap, struct ListNode** lists, int listsIndex, int* heapSize){
    minHeap[*heapSize].listNode = lists[listsIndex];
    minHeap[*heapSize].listsIndex = listsIndex;

    MIN_HEAP(minHeap, *heapSize);

    *heapSize = *heapSize + 1;

    lists[listsIndex] = lists[listsIndex]->next;
}

int EXTRACT_MIN(struct HeapNode* minHeap, struct ListNode** listTail, int* heapSize){
    int listsIndex = minHeap[0].listsIndex;
    (*listTail)->next = minHeap[0].listNode;
    *listTail = (*listTail)->next;

    *heapSize = *heapSize - 1;
    minHeap[0].listsIndex = minHeap[*heapSize].listsIndex;
    minHeap[0].listNode = minHeap[*heapSize].listNode;
    int i = *heapSize-1;
    for(; i>0; i--){
        MIN_HEAP(minHeap, i);
    }

    return listsIndex;
}

struct ListNode* mergeKListsWithHeap(struct ListNode** lists, int listsSize) {
    if(listsSize<2){
        return lists[0];
    }
    struct ListNode result = {0, NULL};
    struct ListNode* tail = &result;
    int heapSize = 0;
    struct HeapNode* minHeap = (struct HeapNode*)malloc(listsSize*sizeof(struct HeapNode));
    int i = 0;
    int minIndex = 0;
    int undo = listsSize;
    for(i=0; i<listsSize; i++){
        if(lists[i]!=NULL){
            INSERT_MIN_HEAP(minHeap, lists, i, &heapSize);
        }else{
            undo--;
        }
    }
    while(undo){
        //将最小heapnode的从堆中取出，其中listNode指针赋给tail->next,tail=tail->next
        //同时返回所取最小heapnode在lists中的索引listsIndex
        minIndex = EXTRACT_MIN(minHeap, &tail, &heapSize);
        if(lists[minIndex]!=NULL){
            INSERT_MIN_HEAP(minHeap, lists, minIndex, &heapSize);
        }else{
            undo--;
        }
    }
    while(heapSize){
        EXTRACT_MIN(minHeap, &tail, &heapSize);
    }
    return result.next;
}

void mergeKListsWithHeapMain(void){



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    //[[-10,-9,-9,-3,-1,-1,0],[-5],[4],[-8],[],[-9,-6,-5,-4,-2,2,3],[-3,-3,-2,-1,0]]
//    struct ListNode list1[7] = { {-10, &list1[1]},
//    {-9, &list1[2]},
//    {-9, &list1[3]},
//    {-3, &list1[4]},
//    {-1, &list1[5]},
//    {-1, &list1[6]},
//    {0, NULL} };
//    struct ListNode list2[1] = { {-5, NULL}
//    };
//    struct ListNode list3[1] = { {4, NULL}
//    };
//    struct ListNode list4[1] = { {-8, NULL}
//    };
//    struct ListNode* list5 = NULL;
//    struct ListNode list6[7] = { {-9, &list6[1]},
//    {-6, &list6[2]},
//    {-5, &list6[3]},
//    {-4, &list6[4]},
//    {-2, &list6[5]},
//    {2, &list6[6]},
//    {3, NULL} };
//    struct ListNode list7[5] = { {-3, &list7[1]},
//    {-3, &list7[2]},
//    {-2, &list7[3]},
//    {-1, &list7[4]},
//    {0, NULL} };
//
//    struct ListNode* lists[7] = {
//        list1,
//        list2,
//        list3,
//        list4,
//        list5,
//        list6,
//        list7,
//        };
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//    struct ListNode list1 = {
//        .val = 0,
//        .next = NULL
//    };
//    struct ListNode list2 = {
//        .val = 1,
//        .next = NULL
//    };
//    struct ListNode list3 = {
//        .val = 0,
//        .next = NULL
//    };

//    struct ListNode* lists[3] = {
//        &list1,
//        &list2,
//        &list3
//        };

//    struct ListNode* lists[3] = {NULL, &list2, NULL};

//    struct ListNode* lists[4] = {NULL, &list1, NULL, &list2};

    struct ListNode* tail = &list1;
    int i = 0;

//    for(i=0; i<10; i++){
//        tail->val = i;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;
//    tail = &list2;
//    for(i=5; i<15; i++){
//        tail->val = i;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;
//    tail = &list3;
//    for(i=10; i<20; i++){
//        tail->val = i;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;

//    for(i=10; i>0; i--){
//        tail->val = i;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        //tail->next->val = i;
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;
//    tail = &list2;
//    for(i=15; i>5; i--){
//        tail->val = i;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        //tail->next->val = i;
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;
//    tail = &list3;
//    for(i=20; i>10; i--){
//        tail->val = i;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        //tail->next->val = i;
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;

//    for(i=0; i<10; i++){
//        tail->val = 1;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;
//    tail = &list2;
//    for(i=5; i<15; i++){
//        tail->val = 2;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;
//    tail = &list3;
//    for(i=10; i<20; i++){
//        tail->val = 3;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = i;

//    int nums1[3] = {1,2,2};
//    int nums2[3] = {1,1,2};
//    for(i=0; i<2; i++){
//        tail->val = nums1[i];
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = nums1[i];
//    tail = &list2;
//    for(i=0; i<2; i++){
//        tail->val = nums2[i];
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = nums2[i];

//    for(i=0; i<10; i++){
//        tail->val = 3;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = 3;
//    tail = &list2;
//    for(i=5; i<15; i++){
//        tail->val = 2;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = 2;
//    tail = &list3;
//    for(i=10; i<20; i++){
//        tail->val = 1;
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val =1;

//    int nums1[3] = {-1,5,11};
//    int nums2[3] = {6,10};
////    int nums1[3] = {5,5,5};
////    int nums2[3] = {6,6};
//    for(i=0; i<2; i++){
//        tail->val = nums1[i];
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = nums1[i];
//    tail = &list2;
//    for(i=0; i<1; i++){
//        tail->val = nums2[i];
//        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        tail->next->next = NULL;
//        tail = tail->next;
//    }
//    tail->val = nums2[i];


    //struct ListNode* result = mergeKListsWithHeap(lists, 10000);//堆排序实现效果没有下面分治的好
    struct ListNode* result = mergeKLists(lists, 10000);
    //mergeKLists(lists, 4);

    while(result){
        printf("%d\n", result->val);
        tail = result;
        result = result->next;
        free(tail);
    }
}
