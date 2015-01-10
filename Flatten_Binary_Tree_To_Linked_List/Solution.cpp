/**
* Created by Yu(Khitan) Wu on 1/9/2015
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
	void flatten(TreeNode *root) {
		if (root == NULL) return;
		TreeNode *current = root, *left = root->left, *right = root->right;
		if (left != NULL) DFS(left, current);
		if (right != NULL) DFS(right, current);
	}

	void DFS(TreeNode *root, TreeNode * &current){
		TreeNode *left = root->left, *right = root->right;
		current->right = root; current->left = NULL;
		current = current->right;
		if (left != NULL)  DFS(left, current);
		if (right != NULL) DFS(right, current);
	}

};