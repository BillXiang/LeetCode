#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* p = head;
    struct ListNode* removed = head;
    struct ListNode* pre = NULL;
    int i = 0;
    for(i=0; i<n; i++){
        p = p->next;
    }
    while(head){
        p = p->next;
        pre = removed;
        removed = removed->next;
    }
    if(pre!=NULL){
        pre->next = removed->next;
    }else{
        head = NULL;
    }
    free(removed);
    return head;
}

void removeNthFromEndMain(void){

}
