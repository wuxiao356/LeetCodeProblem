/**
* Created by Yu(Khitan) Wu on 1/9/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result = { 0 };
		if (n == 0) return result;
		result.push_back(1);
		if (n == 1) return result;

		vector<int> lastAns = grayCode(n - 1);
		for (int i = lastAns.size() - 1; i >= 0; --i){
			lastAns.push_back(lastAns[i] + pow(2, n - 1));
		}
		return lastAns;
	}
};