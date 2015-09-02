/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        stack<TreeNode*> treeInorderStack;
        TreeNode* top = root;

        while(top!=NULL){
            treeInorderStack.push(top);
            top = top->left;
        }
        do{
            top = treeInorderStack.top();
            treeInorderStack.pop();
            result.push_back(top->val);

            if(top->right!=NULL){
                top = top->right;
                while(top!=NULL){
                    treeInorderStack.push(top);
                    top = top->left;
                }
            }

        }while(!treeInorderStack.empty());

        return result;
    }
};

void inorderTraversalTest(void){
    Solution solution = Solution();
    TreeNode tree[] = {
        TreeNode(0, &tree[1], &tree[2]),
        TreeNode(1, &tree[3], &tree[4]),
        TreeNode(2, NULL, NULL),
        TreeNode(3, NULL, NULL),
        TreeNode(4, NULL, NULL),
    };
    vector<int> result = solution.inorderTraversal(tree);
    for(vector<int>::iterator iter = result.begin(); iter!=result.end(); iter++){
        cout<<*iter<<endl;
    }
}
