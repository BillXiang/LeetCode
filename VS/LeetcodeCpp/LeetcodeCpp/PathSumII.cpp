/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1

return

[
[5,4,11,2],
[5,8,4,5]
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
#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <list>
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
	vector< vector<int> > pathSum(TreeNode* root, int sum) {
		vector< vector<int> > results;
		if (root == NULL){
			return results;
		}
		list<TreeNode*> path;
		TreeNode* top = root;
		path.push_back(top);
		while (!path.empty()){
			while (top->left != NULL){
				top->left->val += top->val;
				top = top->left;
				path.push_back(top);
			}//左分支遍历完了
			if (top->right != NULL){//右分支
				top->right->val += top->val;
				top = top->right;
				path.push_back(top);
			}
			else{
				if (top->val == sum){//左右节点都为NULL，叶子节点
					vector<int> result;
					for (list<TreeNode*>::iterator ite = path.begin(); ite != path.end(); ite++){
						result.push_back((*ite)->val);
					}
					results.push_back(result);
				}
				path.pop_back();
				while (!path.empty() && path.back()->right == top){
					//被弹出节点是其父节点的右孩子，继续弹出
					top = path.back();
					path.pop_back();
				}
				while (!path.empty() && path.back()->left == top && path.back()->right == NULL){
					//被弹出节点是其父节点的左孩子，并且父节点没有右孩子，继续弹出
					top = path.back();
					path.pop_back();
				}
				if (!path.empty() && top->right != NULL){//将右孩子压入
					top->right->val += top->val;
					top = top->right;
					path.push_back(top);
				}
			}
		}
		return results;
	}
};
void pathSumMain(void){
	TreeNode tree[] = {
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
		//        TreeNode(-2, NULL, NULL),
		//        TreeNode(3, NULL, NULL),
	};
	list<TreeNode*> integers;
	TreeNode* p = &tree[0];
	integers.push_back(p);
	p = &tree[1];
	integers.push_back(p);
	p = &tree[2];
	integers.push_back(p);
	p = &tree[3];
	integers.push_back(p);
	//    for(list<TreeNode*>::iterator ite=integers.begin(); ite!=integers.end(); ite++){
	//        cout<<(*ite)->val<<endl;
	//    }
	while (!integers.empty()){
		cout << integers.back()->val << endl;
		integers.pop_back();
	}
	vector< vector<int> > results = Solution().pathSum(tree, 22);
	for (vector< vector<int> >::iterator ite1 = results.begin(); ite1 != results.end(); ite1++){
		for (vector<int>::iterator ite2 = (*ite1).begin(); ite2 != (*ite1).end(); ite2++){
			cout << *ite2 << endl;
		}
	}
}
