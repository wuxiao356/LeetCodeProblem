/**
 * Created by Yu(Khitan) Wu on 12/11/2014
<<<<<<< HEAD
 * Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
 * Email: wuxiao356@gmial.com
=======
 * Copyright (C) 2014 Yu(Khitna) Wu All rights reserved.
 * Email: wuxiao356@gmail.com
>>>>>>> origin/master
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
#include <queue>

class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {

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
		// v's order is from root to leaf; result's order is from leaf to root
		vector<vector<int>> result;
		for (int i = v.size() - 1; i >= 0; --i){
			result.push_back(v[i]);
		}

		return result;
	}
};
