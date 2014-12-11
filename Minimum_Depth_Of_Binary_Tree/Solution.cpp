/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <climits>

class Solution {
public:
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;
		int height = 0;
		return minDFS(root, height);
	}

	int minDFS(TreeNode *root, int depth){
		++depth;
		int minDepth = depth, leftDepth = INT_MAX, rightDepth = INT_MAX;
		if (root->left == NULL && root->right == NULL) return minDepth;
		if (root->left != NULL) leftDepth = minDFS(root->left, depth);
		if (root->right != NULL) rightDepth = minDFS(root->right, depth);

		int tempDepth = leftDepth;
		if (rightDepth < leftDepth) tempDepth = rightDepth;
		return tempDepth;
	}
};