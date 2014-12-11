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