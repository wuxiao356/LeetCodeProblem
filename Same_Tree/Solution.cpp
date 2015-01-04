/**
* Created by Yu(Khitan) Wu on 1/4/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) return true;
		else if (p != NULL && q != NULL && p->val == q->val){
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else return false;
	}
};