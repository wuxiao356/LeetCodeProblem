/**
* Created by Yu(Khitan) Wu on 12/27/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
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
	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;
		else{
			if (abs((height(root->left) - height(root->right))) > 1) return false;
			else return (isBalanced(root->left) && isBalanced(root->right));
		}
	}
	int height(TreeNode *root){
		if (root == NULL) return 0;
		return 1 + max(height(root->left), height(root->right));
	}
};