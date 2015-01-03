/**
* Created by Yu(Khitan) Wu on 1/3/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int end = n - 1;
		while (A[end] == elem){
			--end;
			if (end == -1) return 0;
		}
		int i = 0;
		while (i <= end){
			if (A[i] == elem){
				A[i] = A[end];
				--end;
				while (A[end] == elem){
					--end;
					if (end == i) return i + 1;
				}
			}
			++i;
		}
		return i;
	}
};