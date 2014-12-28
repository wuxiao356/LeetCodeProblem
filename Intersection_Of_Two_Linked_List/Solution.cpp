/**
* Created by Yu(Khitan) Wu on 12/27/2014
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		int sizeA = 1, sizeB = 1;
		ListNode *iterA = headA, *iterB = headB;
		while (iterA->next != NULL){
			++sizeA;
			iterA = iterA->next;
		}
		while (iterB->next != NULL){
			++sizeB;
			iterB = iterB->next;
		}
		if (iterA != iterB) return NULL;
		ListNode *intersection = NULL;
		if (sizeA < sizeB) intersection = findIntersection(headA, headB, sizeB - sizeA);
		else intersection = findIntersection(headB, headA, sizeA - sizeB);
		return intersection;
	}
	// size of listB is larger than size of list A
	ListNode *findIntersection(ListNode *headA, ListNode *headB, int sizeDiff){
		while (sizeDiff != 0){
			headB = headB->next;
			--sizeDiff;
		}
		while (headB != headA){ headB = headB->next; headA = headA->next; }
		return headB;
	}
};