/**
* Created by Yu(Khitan) Wu on 12/29/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode * p1 = head, *p2 = head, *p3 = head;
		int index = 0;
		while (p3 != NULL){
			p3 = p3->next;
			if (index >= n) p2 = p2->next;
			if (index >= n + 1) p1 = p1->next;
			++index;
		}
		if (p2 == head) return p2->next;
		p1->next = p2->next;
		return head;
	}
};