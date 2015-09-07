/**
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.


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
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
struct Result{
    int maxToRootSum;
    int maxPathSum;
};
class Solution {
public:
    struct Result maxPath(TreeNode* root){
        if(root==NULL){
            struct Result result = {INT_MIN, INT_MIN};
            return result;
        }else{
            struct Result l = maxPath(root->left);
            struct Result r = maxPath(root->right);
            int maxPathSum = root->val;
            if(l.maxToRootSum>0){
                maxPathSum += l.maxToRootSum;
            }
            if(r.maxToRootSum>0){
                maxPathSum += r.maxToRootSum;
            }

            if(maxPathSum<l.maxPathSum){
                maxPathSum = l.maxPathSum;
            }
            if(maxPathSum<r.maxPathSum){
                maxPathSum = r.maxPathSum;
            }

            int maxToRootSum = root->val;
            if(l.maxToRootSum>r.maxToRootSum && l.maxToRootSum>0){
                maxToRootSum += l.maxToRootSum;
            }else if(r.maxToRootSum>0){
                maxToRootSum += r.maxToRootSum;
            }
            struct Result result = {maxToRootSum , maxPathSum};
            return result;
        }

    };
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return maxPath(root).maxPathSum;
    }
};

void maxPathSumMain(void){
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

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(-2, &tree[3], &tree[4]),
//        TreeNode(3, &tree[5], NULL),
//        TreeNode(1, &tree[6], NULL),
//        TreeNode(3, NULL, NULL),
//        TreeNode(-2, NULL, NULL),
//        TreeNode(-1, NULL, NULL),

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(2, NULL, NULL),
//        TreeNode(2, NULL, NULL),
        TreeNode(1, &tree[1], NULL),
        TreeNode(2, NULL, NULL),
    };
    cout<<Solution().maxPathSum(tree)<<endl;
}
