/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
#include <stack>
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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        stack<TreeNode*> path;
        TreeNode* top = root;
        path.push(top);
        int maxDepth = 1;
        int curDepth = 1;
        while(!path.empty()){
            while(top->left!=NULL){
                curDepth++;
                path.push(top->left);
                top = top->left;
            }
            if(top->right==NULL){
                maxDepth = maxDepth<curDepth?curDepth:maxDepth;

                path.pop();
                curDepth--;

                while(!path.empty() &&
                        ( (path.top()->left==top && path.top()->right==NULL) ||
                          (path.top()->right==top) )){
                    //弹出的是左节点，并且没有右节点，则继续弹出
                    //弹出的是右节点，则继续弹出
                    top = path.top();
                    path.pop();
                    curDepth--;
                }
            }
            if(!path.empty() && path.top()->right!=NULL){
                top = path.top()->right;
                path.push(top);
                curDepth++;
            }
        }
        return maxDepth;
    }
};
void maxDepthMain(void){
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
    };

    cout<<Solution().maxDepth(tree)<<endl;
}
