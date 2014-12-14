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
class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;
		int height = 0;
		return maxDFS(root, height);
	}

	int maxDFS(TreeNode *root, int depth){
		++depth;
		int leftDepth = 0, rightDepth = 0;
		if (root->left == NULL && root->right == NULL) return depth;

		if (root->left != NULL) leftDepth = maxDFS(root->left, depth);
		if (root->right != NULL) rightDepth = maxDFS(root->right, depth);

		int tempDepth = leftDepth;
		if (leftDepth < rightDepth) tempDepth = rightDepth;
		return tempDepth;
	}
};
