/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7

return its zigzag level order traversal as:

[
[3],
[20,9],
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
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <list>
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
	vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
		vector< vector<int> > result;
		if (root == NULL){
			return result;
		}
		list<TreeNode*> leftList;
		list<TreeNode*> rightList;
		TreeNode* top = NULL;
		leftList.push_back(root);
		while (!leftList.empty() || !rightList.empty()){
			vector<int> leftLevel;
			while (!leftList.empty()){
				top = leftList.front();
				leftLevel.push_back(top->val);
				if (top->left != NULL)
					rightList.push_front(top->left);
				if (top->right != NULL)
					rightList.push_front(top->right);
				leftList.pop_front();
			}
			if (leftLevel.size()!=0)
				result.push_back(leftLevel);
			vector<int> rightLevel;
			while (!rightList.empty()){
				top = rightList.front();
				rightLevel.push_back(top->val);
				if (top->right != NULL)
					leftList.push_front(top->right);
				if (top->left != NULL)
					leftList.push_front(top->left);
				rightList.pop_front();
			}
			if (rightLevel.size()!=0)
				result.push_back(rightLevel);
		}
		return result;
	}
};

void zigzagLevelOrderMain(void){
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

		/*TreeNode(1, &tree[1], &tree[2]),
		TreeNode(-2, &tree[3], &tree[4]),
		TreeNode(3, &tree[5], NULL),
		TreeNode(1, &tree[6], NULL),
		TreeNode(3, NULL, NULL),
		TreeNode(-2, NULL, NULL),
		TreeNode(-1, NULL, NULL),*/
	};
	vector< vector<int> > result = Solution().zigzagLevelOrder(tree);
	for (vector< vector<int> >::iterator ite1 = result.begin(); ite1 != result.end(); ite1++){
		for (vector<int>::iterator ite2 = (*ite1).begin(); ite2 != (*ite1).end(); ite2++){
			cout << *ite2 << " ";
		}
		cout << endl;
	}
}
