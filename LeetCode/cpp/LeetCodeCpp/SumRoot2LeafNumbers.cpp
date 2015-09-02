/**
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;

        int result = 0;
        stack<TreeNode*> sumTree;
        sumTree.push(root);
        TreeNode* top = root;
        int tmp = 0;
        while(!sumTree.empty()){
            top = sumTree.top();
            if(top->left==NULL && top->right==NULL){//叶子节点
                result += top->val;
                sumTree.pop();
                while(!sumTree.empty() && (top==sumTree.top()->left || top==sumTree.top()->right)){
                    //子节点已经全部弹出，则将父节点也弹出
                    top = sumTree.top();
                    sumTree.pop();
                }
            }else{
                tmp = top->val*10;
                if(top->left!=NULL){
                    top->left->val += tmp;
                    sumTree.push(top->left);
                }
                if(top->right!=NULL){
                    top->right->val += tmp;
                    sumTree.push(top->right);
                }
            }
        }
        return result;
    }
};

void sumNumbersMain(void){
    TreeNode tree[] = {
        TreeNode(1, &tree[1], &tree[2]),
        TreeNode(1, &tree[3], &tree[4]),
        TreeNode(2, NULL, NULL),
        TreeNode(3, NULL, NULL),
        TreeNode(4, NULL, NULL)
    };
    cout<<Solution().sumNumbers(tree)<<endl;
}
