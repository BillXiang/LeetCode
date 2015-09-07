/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
#include <math.h>

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
    bool isBalanced(TreeNode* root, /*int* minDepth,*/ int* maxDepth){
        if(root==NULL){
            //*minDepth = -1;
            *maxDepth = -1;
            return true;
        }
        //int lMinDepth = 0;
        int lMaxDepth = 0;
        int lBalanced = isBalanced(root->left, /*&lMinDepth,*/ &lMaxDepth);

        //int rMinDepth = 0;
        int rMaxDepth = 0;
        int rBalanced = isBalanced(root->right, /*&rMinDepth,*/ &rMaxDepth);

        //*minDepth = (lMinDepth>rMinDepth?rMinDepth:lMinDepth) + 1;
        *maxDepth = (lMaxDepth>rMaxDepth?lMaxDepth:rMaxDepth) + 1;
        //return lBalanced && rBalanced && ( *maxDepth-*minDepth<=1 );
        return lBalanced && rBalanced && ( abs(lMaxDepth-rMaxDepth)<=1 );
    }
    bool isBalanced(TreeNode* root) {
        //int minDepth = 0;
        int maxDepth = 0;
        return isBalanced(root, /*&minDepth,*/ &maxDepth);
    }
};

void isBalancedMain(void){
    TreeNode tree[]={
//            TreeNode(5, &tree[1], &tree[2]),
//            TreeNode(4, &tree[3], NULL),
//            TreeNode(8, &tree[4], &tree[5]),
//            TreeNode(11, &tree[6], &tree[7]),
//            TreeNode(13, NULL, NULL),
//            TreeNode(4, &tree[8], &tree[9]),
//            TreeNode(7, NULL, NULL),
//            TreeNode(2, NULL, NULL),
//            TreeNode(5, NULL, NULL),
//            TreeNode(1, NULL, NULL),

    //        TreeNode(1, &tree[1], NULL),
    //        TreeNode(2, NULL, NULL),

        TreeNode(1, &tree[1], &tree[2]),
        TreeNode(-2, &tree[3], &tree[4]),
        TreeNode(3, &tree[5], NULL),
        TreeNode(1, &tree[6], NULL),
        TreeNode(3, NULL, NULL),
        TreeNode(-2, NULL, NULL),
        TreeNode(-1, NULL, NULL),

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(2, NULL, NULL),
//        TreeNode(2, NULL, NULL),

//        TreeNode(1, &tree[1], NULL),
//        TreeNode(2, NULL, NULL),

//        TreeNode(1, NULL, &tree[1]),
//        TreeNode(3, &tree[2], NULL),
//        TreeNode(2, NULL, NULL),
    };
    cout<<Solution().isBalanced(tree)<<endl;
}
