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
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		return isSame(root->left, root->right);
	}

	bool isSame(TreeNode *l, TreeNode *r){
		if (l == NULL && r == NULL) return true;
		else if (l != NULL && r != NULL && l->val == r->val){
			return isSame(l->left, r->right) && isSame(l->right, r->left);
		}
		else return false;
	}
};