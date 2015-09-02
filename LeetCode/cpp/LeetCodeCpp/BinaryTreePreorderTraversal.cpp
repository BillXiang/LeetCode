/**
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

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
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;

        stack<TreeNode*> preorderStack;
        preorderStack.push(root);
        while(!preorderStack.empty()){
            TreeNode* node = preorderStack.top();
            result.push_back(node->val);
            preorderStack.pop();
            if(node->right!=NULL)
                preorderStack.push(node->right);
            if(node->left!=NULL)
                preorderStack.push(node->left);
        }
        return result;
    }
};

void preorderTraversalMain(void){
    Solution solution = Solution();
    TreeNode tree[] = { TreeNode(1, &tree[1], &tree[2]),
        TreeNode(4, &tree[3], &tree[4]),
        TreeNode(3, NULL, NULL),
        TreeNode(2, NULL, NULL),
        TreeNode(5, NULL, NULL)
    };
    vector<int> result = solution.preorderTraversal(tree);
    for(vector<int>::iterator iter=result.begin(); iter!=result.end(); iter++){
        cout<< *iter << "\n" << endl;
    }
}
