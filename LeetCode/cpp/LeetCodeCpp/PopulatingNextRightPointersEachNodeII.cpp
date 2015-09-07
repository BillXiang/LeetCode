/**
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
        if(levelStart==NULL){
            levelStart = root->right;
        }
        TreeLinkNode* levelEnd = levelStart;

        while(levelStart!=NULL){
            while(upLevel!=NULL){
                while(upLevel!=NULL && upLevel->left==NULL && upLevel->right==NULL){
                    upLevel = upLevel->next;//跳过没有子节点的
                }
                if(upLevel!=NULL){
                    if(upLevel->left!=NULL && levelStart!=upLevel->left ){//当前levelEnd指向upLevel->left
                        levelEnd->next = upLevel->left;
                        levelEnd = levelEnd->next;
                        if(upLevel->right!=NULL){
                            levelEnd->next = upLevel->right;
                            levelEnd = levelEnd->next;
                        }
                    }else if(upLevel->right!=NULL && levelStart!=upLevel->right){
                        levelEnd->next = upLevel->right;
                        levelEnd = levelEnd->next;
                    }
                    upLevel = upLevel->next;
                }
            }

            upLevel = levelStart;
            while(levelStart!=NULL && levelStart->left==NULL && levelStart->right==NULL){
                levelStart = levelStart->next;//跳过没有子节点的
            }
            if(levelStart!=NULL){
                if(levelStart->left!=NULL){
                    levelStart = levelStart->left;
                }else{
                    levelStart = levelStart->right;
                }
                levelEnd = levelStart;
            }
        }
    }
};
