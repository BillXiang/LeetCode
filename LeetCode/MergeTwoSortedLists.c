struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdlib.h>
/**
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    struct ListNode result = {0, NULL};
    struct ListNode* p = &result;
    while(l1 && l2){
        if(l1->val > l2->val){
            p->next = l2;
            l2 = l2->next;
        }else{
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    if(l1){
        p->next = l1;
    }else if(l2){
        p->next = l2;
    }
    return result.next;
}
