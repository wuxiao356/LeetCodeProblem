/**
* Created by Yu(Khitan) Wu on 1/3/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1, j = n - 1;
		for (int index = m + n - 1; index >= 0; --index){
			if (i < 0) { A[index] = B[j]; --j; }
			else if (j < 0) { A[index] = A[i]; --i; }
			else if (A[i] >= B[j]) { A[index] = A[i]; --i; }
			else { A[index] = B[j]; --j; }
		}
	}
};