/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

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
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        stack<TreeNode*> postorderTree;
        TreeNode* p = root;
        postorderTree.push(p);

        while(p!=NULL){
            while(p->left!=NULL){
                postorderTree.push(p->left);
                p = p->left;
            }
            p = p->right;
            if(p!=NULL){
                postorderTree.push(p);
            }
        }
        p = postorderTree.top();
        postorderTree.pop();
        result.push_back(p->val);

        while(!postorderTree.empty()){
            if(p==postorderTree.top()->left){
                //被弹出的节点是其父节点的左子节点，则将右子节点加入
                p = postorderTree.top()->right;
                if(p!=NULL){
                    postorderTree.push(p);
                }

                while(p!=NULL){
                    while(p->left!=NULL){
                        postorderTree.push(p->left);
                        p = p->left;
                    }
                    p = p->right;
                    if(p!=NULL){
                        postorderTree.push(p);
                    }
                }
                p = postorderTree.top();
                postorderTree.pop();
                result.push_back(p->val);

            }else if(p==postorderTree.top()->right){
                //被弹出的节点是其父节点的右子节点，则将父节点弹出
                p = postorderTree.top();
                postorderTree.pop();
                result.push_back(p->val);
            }
        }
        return result;
    }
};

void postorderTraversalMain(void){
    TreeNode postorderTree[] = {
        TreeNode(0, &postorderTree[1], &postorderTree[2]),
        TreeNode(1, &postorderTree[3], &postorderTree[4]),
        TreeNode(2, NULL, NULL),
        TreeNode(3, NULL, NULL),
        TreeNode(4, NULL, NULL),
    };
    vector<int> result = Solution().postorderTraversal(postorderTree);
    for(vector<int>::iterator iter=result.begin(); iter!=result.end(); iter++){
        cout<<*iter<<endl;
    }
}
