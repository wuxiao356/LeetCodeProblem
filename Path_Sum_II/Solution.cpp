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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> result;
		if (root == NULL) return result;
		vector<int> i;
		DFS(root, 0, sum, i, result);
		return result;
	}

	void DFS(TreeNode *root, int subSum, int sum, vector<int> &path, vector<vector<int>> &result){
		path.push_back(root->val);
		subSum += root->val;
		if (root->left == NULL && root->right == NULL){
			if (subSum == sum)  result.push_back(path);
		}
		else{
			if (root->left != NULL) { DFS(root->left, subSum, sum, path, result); path.erase(path.end() - 1); }
			if (root->right != NULL) { DFS(root->right, subSum, sum, path, result); path.erase(path.end() - 1); }
		}
	}
};