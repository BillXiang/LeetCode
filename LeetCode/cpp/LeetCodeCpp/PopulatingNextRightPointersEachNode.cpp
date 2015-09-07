/**
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
**/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL){
            return;
        }
        vector<TreeLinkNode*> tree;
        tree.push_back(root);
        tree.push_back(NULL);
        int startIte = 0;
        int endIte = 1;
        while(startIte!=endIte){
            if(tree[startIte]->right!=NULL){

                tree[startIte]->right->next = tree.back();

                tree.push_back(tree[startIte]->right);
            }
            if(tree[startIte]->left!=NULL){

                tree[startIte]->left->next = tree.back();

                tree.push_back(tree[startIte]->left);
            }
            startIte++;
            if(tree[startIte]==NULL){
                tree.push_back(NULL);
                endIte = tree.size()-1;
                startIte++;
            }
        }
    }
    void connectWithconstantSpace(TreeLinkNode *root) {
        if(root==NULL){
            return;
        }
        TreeLinkNode* upLevel = root;

        TreeLinkNode* levelStart = root->left;
        TreeLinkNode* levelEnd = root->left;

        while(levelStart!=NULL){
            while(upLevel->next!=NULL){
                levelEnd->next = upLevel->right;
                levelEnd = levelEnd->next;
                upLevel = upLevel->next;
                levelEnd->next = upLevel->left;
                levelEnd = levelEnd->next;
            }
            levelEnd->next = upLevel->right;

            upLevel = levelStart;
            levelStart = levelStart->left;
            levelEnd = levelStart;
        }
    }
};
