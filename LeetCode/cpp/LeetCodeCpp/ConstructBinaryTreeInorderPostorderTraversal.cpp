/**
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, int iStart, int iEnd,
                        vector<int>& postorder, int pStart, int pEnd) {
        TreeNode* root = new TreeNode(postorder[pEnd]);
        if(iStart==iEnd){
            return root;
        }
        int rootIndexInorder = 0;
        for(int i=iStart; i<=iEnd; i++){
            if(inorder[i]==postorder[pEnd]){
                rootIndexInorder = i;
            }
        }
        if(rootIndexInorder==iStart){//没有左节点
            root->right = buildTree(inorder, iStart+1, iEnd, postorder, pStart, pEnd-1);
        }else if(rootIndexInorder==iEnd){//没有右节点
            root->left = buildTree(inorder, iStart, iEnd-1, postorder, pStart, pEnd-1);
        }else{
            root->left = buildTree(inorder, iStart, rootIndexInorder-1,
                                   postorder, pStart, pStart+rootIndexInorder-iStart-1);
            root->right = buildTree(inorder, rootIndexInorder+1, iEnd,
                                    postorder, pStart+rootIndexInorder-iStart, pEnd-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0){
            return NULL;
        }
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
