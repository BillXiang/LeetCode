/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
#include <stack>
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        stack<TreeNode*> tree;
        tree.push(root);
        TreeNode* top = root;

        while(!tree.empty()){
            top = tree.top();
            if(top->left==NULL && top->right==NULL){//叶子节点
                if(top->val==sum){
                    return true;
                }
                tree.pop();
                while(!tree.empty() && (top==tree.top()->left || top==tree.top()->right)){
                    top = tree.top();
                    tree.pop();//子节点已经被弹出，则父节点也弹出
                }
            }else{
                if(top->left!=NULL){
                    top->left->val += top->val;
//                    if(top->left->val<=sum){
                        tree.push(top->left);
//                    }else if(top->right==NULL){
//                        //左分支没有加入，并且右分支为空，则弹出当前节点
//                        tree.pop();
//                        while(!tree.empty() && (top==tree.top()->left || top==tree.top()->right)){
//                            top = tree.top();
//                            tree.pop();//子节点已经被弹出，则父节点也弹出
//                        }
//                        continue;
//                    }
                }
                if(top->right!=NULL){
                    top->right->val += top->val;
//                    if(top->right->val<=sum){
                        tree.push(top->right);
//                    }else{
//                        tree.pop();
//                        while(!tree.empty() && (top==tree.top()->left || top==tree.top()->right)){
//                            top = tree.top();
//                            tree.pop();//子节点已经被弹出，则父节点也弹出
//                        }
//                    }
                }
            }
        }
        return false;
    }
};

void hasPathSumMain(void){
    TreeNode tree[]={
        TreeNode(5, &tree[1], &tree[2]),
        TreeNode(4, &tree[3], NULL),
        TreeNode(8, &tree[4], &tree[5]),
        TreeNode(11, &tree[6], &tree[7]),
        TreeNode(13, NULL, NULL),
        TreeNode(4, NULL, &tree[8]),
        TreeNode(7, NULL, NULL),
        TreeNode(2, NULL, NULL),
        TreeNode(1, NULL, NULL),

//        TreeNode(1, &tree[1], NULL),
//        TreeNode(2, NULL, NULL),

//        TreeNode(1, &tree[1], &tree[2]),
//        TreeNode(-2, NULL, NULL),
//        TreeNode(3, NULL, NULL),
    };
    cout<<Solution().hasPathSum(tree, 22)<<endl;
}
