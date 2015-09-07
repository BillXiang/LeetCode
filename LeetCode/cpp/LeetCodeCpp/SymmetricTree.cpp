/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
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
#include <stdbool.h>

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
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left==NULL){
            return right==NULL;
        }
        if(right==NULL){
            return false;
        }
        return (left->val==right->val) &&
                isSymmetric(left->left, right->right) &&
                isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
};

void isSymmetricMain(void){
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
        TreeNode(1, &tree[1], &tree[2]),
        TreeNode(2, NULL, NULL),
        TreeNode(2, NULL, NULL),
    };
    cout<<Solution().isSymmetric(tree)<<endl;
}
