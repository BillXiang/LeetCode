/**
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }else if(root->left==NULL){
            return minDepth(root->right)+1;
        }else if(root->right==NULL){
            return minDepth(root->left)+1;
        }else{
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            if(l<r){
                return l+1;
            }else{
                return r+1;
            }
        }
    }
};
void minDepthMain(void){
    TreeNode tree[]={
//        TreeNode(5, &tree[1], &tree[2]),
//        TreeNode(4, &tree[3], NULL),
//        TreeNode(8, &tree[4], &tree[5]),
//        TreeNode(11, &tree[6], &tree[7]),
//        TreeNode(13, NULL, NULL),
//        TreeNode(4, &tree[8], &tree[9]),
//        TreeNode(7, NULL, NULL),
//        TreeNode(2, NULL, NULL),
//        TreeNode(5, NULL, NULL),
//        TreeNode(1, NULL, NULL),

//        TreeNode(1, &tree[1], NULL),
//        TreeNode(2, NULL, NULL),

        TreeNode(1, &tree[1], &tree[2]),
        TreeNode(-2, &tree[3], &tree[4]),
        TreeNode(3, &tree[5], NULL),
        TreeNode(1, &tree[6], NULL),
        TreeNode(3, NULL, NULL),
        TreeNode(-2, NULL, NULL),
        TreeNode(-1, NULL, NULL),
    };

    cout<<Solution().minDepth(tree)<<endl;
}
