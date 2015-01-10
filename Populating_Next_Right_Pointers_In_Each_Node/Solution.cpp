/**
* Created by Yu(Khitan) Wu on 1/9/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
#include <queue>
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		queue<TreeLinkNode*> Q;
		Q.push(root);
		TreeLinkNode *last = NULL;
		int size = Q.size();
		int levelSize = size;
		while (!Q.empty()){
			TreeLinkNode *current = Q.front();
			Q.pop();
			--size;

			if (current->left != NULL) Q.push(current->left);
			if (current->right != NULL) Q.push(current->right);
			if (size < levelSize - 1) { last->next = current; }
			last = current;

			if (size == 0) { size = Q.size(); levelSize = size; }
		}
	}
};