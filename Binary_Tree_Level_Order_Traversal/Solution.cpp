/**
 * Created by Yu(Khitan) Wu on 12/11/2014
 * Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
 * Email: wuxiao356@gmial.com
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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> v;
		if (root == NULL) return v;

		queue<TreeNode*> q;

		q.push(root);
		while (!q.empty()){
			size_t levelSize = q.size();
			vector<int> level;
			while (levelSize != 0){
				TreeNode *node = q.front();
				level.push_back(node->val);
				q.pop();
				if (node->left != NULL) q.push(node->left);
				if (node->right != NULL) q.push(node->right);
				--levelSize;
			}
			v.push_back(level);

		}
		return v;
	}
};
