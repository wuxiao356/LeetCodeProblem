/**
* Created by Yu(Khitan) Wu on 12/26/2014
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
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL) return false;
		return DFS(root, 0, sum);
	}
	bool DFS(TreeNode *root, int subSum, int sum){
		subSum += root->val;
		if (subSum == sum){
			if (root->left == NULL &&  root->right == NULL) return true;
			else{
				bool result = false;
				if (root->left != NULL) result = DFS(root->left, subSum, sum);
				if (!result && root->right != NULL) result = DFS(root->right, subSum, sum);
				return result;
			}
		}
		else{
			bool result = false;
			if (root->left != NULL) result = DFS(root->left, subSum, sum);
			if (!result && root->right != NULL) result = DFS(root->right, subSum, sum);
			return result;
		}
	}
};