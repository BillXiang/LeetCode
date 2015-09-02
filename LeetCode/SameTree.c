/**
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#include <stdbool.h>
#include <stdlib.h>
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //递归
    if(p==NULL) return q==NULL;
    if(q==NULL) return false;
    if(p->val!=q->val) return false;
    return isSameTree(p->right, q->right)
            && isSameTree(p->left, q->left);
}
