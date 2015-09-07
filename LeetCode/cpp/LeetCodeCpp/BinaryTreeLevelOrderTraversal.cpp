/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > result;
        if(root==NULL){
            return result;
        }
        vector<TreeNode*> tree;
        tree.push_back(root);
        tree.push_back(NULL);
        int startIte = 0;
        int endIte = 1;
        result.push_back(vector<int>());
        while(startIte!=endIte){
            if(tree[startIte]->left!=NULL){
                tree.push_back(tree[startIte]->left);
            }
            if(tree[startIte]->right!=NULL){
                tree.push_back(tree[startIte]->right);
            }
            result.back().push_back(tree[startIte]->val);
            startIte++;
            if(tree[startIte]==NULL){
                tree.push_back(NULL);
                endIte = tree.size()-1;
                startIte++;
                if(tree[startIte]!=NULL){
                    result.push_back(vector<int>());
                }else{
                    break;
                }
            }
        }
        return result;
    }
};
void levelOrderMain(void){
    TreeNode tree[]={
            TreeNode(5, &tree[1], &tree[2]),
            TreeNode(4, &tree[3], NULL),
            TreeNode(8, &tree[4], &tree[5]),
            TreeNode(11, &tree[6], &tree[7]),
            TreeNode(13, NULL, NULL),
            TreeNode(4, &tree[8], &tree[9]),
            TreeNode(7, NULL, NULL),
            TreeNode(2, NULL, NULL),
            TreeNode(5, NULL, NULL),
            TreeNode(1, NULL, NULL),

    //        TreeNode(1, &tree[1], NULL),
    //        TreeNode(2, NULL, NULL),

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(-2, &tree[3], &tree[4]),
//        TreeNode(3, &tree[5], NULL),
//        TreeNode(1, &tree[6], NULL),
//        TreeNode(3, NULL, NULL),
//        TreeNode(-2, NULL, NULL),
//        TreeNode(-1, NULL, NULL),

//        TreeNode(3, NULL, &tree[1]),
//        TreeNode(-2, &tree[2], NULL),
//        TreeNode(-1, NULL, NULL),

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(2, NULL, NULL),
//        TreeNode(2, NULL, NULL),

//        TreeNode(1, &tree[1], NULL),
//        TreeNode(2, NULL, NULL),

//        TreeNode(1, NULL, &tree[1]),
//        TreeNode(3, &tree[2], NULL),
//        TreeNode(2, NULL, NULL),
    };
    vector< vector<int> > result = Solution().levelOrder(tree);
    for(vector< vector<int> >::iterator ite1=result.begin(); ite1!=result.end(); ite1++){
        for(vector<int>::iterator ite2=(*ite1).begin(); ite2!=(*ite1).end(); ite2++){
            cout<<*ite2<<" ";
        }
        cout<<endl;
    }
}
