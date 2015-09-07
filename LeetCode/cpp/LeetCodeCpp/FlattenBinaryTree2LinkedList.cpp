/**
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    TreeNode* flattenRecursion(TreeNode* root){
        TreeNode* tail = root;
        if(root==NULL){
            return NULL;
        }else{
            TreeNode* left = NULL;
            TreeNode* right = NULL;
            if(root->left!=NULL){
                left = flattenRecursion(root->left);
            }
            if(root->right!=NULL){
                right = flattenRecursion(root->right);
            }
            root->left = NULL;
            if(left!=NULL){
                tail->right = left;
                tail->left = NULL;
                tail = left;
                while(tail->right!=NULL){
                    tail->left = NULL;
                    tail = tail->right;
                }
            }
            if(right!=NULL){
                tail->right = right;
                tail = right;
                while(tail->right!=NULL){
                    tail->left = NULL;
                    tail = tail->right;
                }
            }
            return root;
        }
    }
    void flatten(TreeNode* root){
        flattenRecursion(root);
    }
};
void flattenMain(void){
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

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(-2, &tree[3], &tree[4]),
//        TreeNode(3, &tree[5], NULL),
//        TreeNode(1, &tree[6], NULL),
//        TreeNode(3, NULL, NULL),
//        TreeNode(-2, NULL, NULL),
//        TreeNode(-1, NULL, NULL),

        TreeNode(3, NULL, &tree[1]),
        TreeNode(-2, &tree[2], NULL),
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
    Solution().flatten(tree);
    TreeNode* head = tree;
    while(head){
        cout<<head->val<<endl;
        head = head->right;
    }
}
