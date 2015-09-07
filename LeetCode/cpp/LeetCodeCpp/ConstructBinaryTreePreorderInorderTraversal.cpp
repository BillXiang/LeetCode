/**
Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& preorder, int pStart, int pEnd,
                        vector<int>& inorder, int iStart, int iEnd){
        TreeNode* root = new TreeNode(preorder[pStart]);
        if(pStart==pEnd){
            return root;
        }
        int rootIndexInorder = 0;
        for(int i=iStart; i<=iEnd; i++){
            if(inorder[i]==preorder[pStart]){
                rootIndexInorder = i;
                break;
            }
        }

        if(rootIndexInorder==iStart){//没有左节点
            root->right = buildTree(preorder, pStart+1, pEnd,
                                    inorder, iStart+1, iEnd);
        }else if(rootIndexInorder==iEnd){//没有右节点
            root->left = buildTree(preorder, pStart+1, pEnd,
                                    inorder, iStart, iEnd-1);
        }else{
            int newLPStart = pStart+1;
            int newLPEnd = pStart+rootIndexInorder-iStart;
            int newLIStart = iStart;
            int newLIEnd = rootIndexInorder-1;
            root->left = buildTree(preorder, newLPStart, newLPEnd,
                                        inorder, newLIStart, newLIEnd);

            int newRPStart = pStart+rootIndexInorder-iStart+1;
            int newRPEnd = pEnd;
            int newRIStart = rootIndexInorder+1;
            int newRIEnd = iEnd;
            root->right = buildTree(preorder, newRPStart, newRPEnd,
                                         inorder, newRIStart, newRIEnd);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0){
            return NULL;
        }
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

void buildTreeMain(void){

}
