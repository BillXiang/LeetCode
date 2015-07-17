#include <stdlib.h>
#include "Tools.h"
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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL || l2==NULL)
        return l1?l1:l2;

    struct ListNode *result, *newNode, *pre;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->next = NULL;
    result = newNode;
    pre = newNode;
    int over = 0;//½øÎ»£¬0»òÕß1
    int tmp = 0;
    while(l1&&l2)
    {
        tmp = l1->val+l2->val+over;
        over = 0;
        if(tmp>9)
        {
            over = 1;
            tmp -= 10;
        }
        newNode->val = tmp;
        pre->next = newNode;
        pre = newNode;

        l1 = l1->next;
        l2 = l2->next;
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
    }
    l1 = l1?l1:l2;
    pre->next = l1;
    while(l1)
    {
        if(over)
        {
            tmp = l1->val+1;
            over = 0;
            if(tmp>9)
            {
                over = 1;
                tmp -= 10;
            }
            l1->val = tmp;
        }
        else
        {
            pre->next = l1;
            break;
        }
        pre = l1;
        l1 = l1->next;
    }
    if(over)
    {
        newNode->val = 1;
        pre->next = newNode;
    }
    else
    {
        free(newNode);
    }
    return result;
}
//测试
void addTwoNumbersMain()
{
    struct ListNode l1[]={ {7, NULL}, {5, NULL}, {1, NULL}, {2, NULL}, {3, NULL} };
    struct ListNode l2[]={ {1, NULL}, {0, NULL}, {9, NULL}, {7, NULL}, {6, NULL}, {9, NULL}, {4, NULL} };
    int len1;
    int len2;
    GET_ARRAY_LEN(l1, len1);
    GET_ARRAY_LEN(l2, len2);

    int i = 0;
    for(i = 0; i<len1-1; i++)
    {
        l1[i].next = &l1[i+1];
    }
    for(i = 0; i<len2-1; i++)
    {
        l2[i].next = &l2[i+1];
    }

    struct ListNode *result = addTwoNumbers(l1, l2);

    while(result)
    {
        printf("%d", result->val);
        result = result->next;
    }
}
