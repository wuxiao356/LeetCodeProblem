/**
* Created by Yu(Khitan) Wu on 1/3/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 2) return n;
		int i = 1, j = 1;
		int value = A[0];
		while (i < n){
			while (A[i] == value && i < n - 1){
				++i;
			}
			if (value == A[i]) break;
			value = A[i];
			A[j] = value;
			++j;
			++i;
		}
		return j;
	}
};