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
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <utility>

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		//key is the value of node, value is the number of duplicates
		unordered_map<int, int> hashTable;
		if (head == NULL) return NULL;

		ListNode *itr = head;
		ListNode *newHead = new ListNode(head->val);
		ListNode *newItr = newHead;
		while (itr != NULL){
			int key = itr->val;
			if (hashTable.find(key) == hashTable.end()){
				hashTable.insert(pair<int, int>(key, 1));
				ListNode *newNode = new ListNode(key);
				newItr->next = newNode;
				newItr = newItr->next;
			}
			itr = itr->next;
		}

		return newHead;
	}
};
