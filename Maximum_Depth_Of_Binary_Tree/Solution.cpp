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
		return DFS(root, height);
	}

	int DFS(TreeNode *root, int depth){
		++depth;
		int maxDepth = depth, leftDepth = 0, rightDepth = 0;
		if (root->left != NULL) leftDepth = DFS(root->left, depth);
		if (root->right != NULL) rightDepth = DFS(root->right, depth);
		int tempDepth = leftDepth;
		if (leftDepth < rightDepth) tempDepth = rightDepth;
		if (tempDepth > maxDepth) maxDepth = tempDepth;

		return maxDepth;
	}
};