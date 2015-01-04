/**
* Created by Yu(Khitan) Wu on 1/3/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;

		ListNode *i = new ListNode(0);
		ListNode *head = i;
		while (l1 != NULL || l2 != NULL){
			if (l1 == NULL){ i->next = l2; i = i->next; l2 = l2->next; }
			else if (l2 == NULL){ i->next = l1; i = i->next; l1 = l1->next; }
			else if (l1->val <= l2->val){ i->next = l1; i = i->next; l1 = l1->next; }
			else{ i->next = l2; i = i->next; l2 = l2->next; }
		}
		return head->next;
	}
};