/**
* Created by Yu(Khitan) Wu on 1/7/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
#include <utility>
#include <algorithm>

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> ans;
		if (num.size() < 3) return ans;

		sort(num.begin(), num.end());
		int lastRepeat = num[0];
		for (size_t i = 0; i < num.size(); ++i){
			if (i > 0 && num[i] == lastRepeat) continue;
			lastRepeat = num[i];
			int x = 0, y = 0;
			twoSum(ans, num, i + 1, num.size() - 1);
		}
		return ans;
	}

	void twoSum(vector<vector<int>> &ans, vector<int> &num, int begin, int end){
		int target = 0 - num[begin - 1];
		int i = begin, j = end;
		while (i < j){
			int sum = num[i] + num[j];
			if (sum == target){
				vector<int> temp = { 0 - target, num[i], num[j] };
				ans.push_back(temp);
				++i;
				while (i < j && num[i] == num[i - 1]) ++i;
				--j;
				while (i < j && num[j] == num[j + 1]) --j;
			}
			else if (sum < target) ++i;
			else --j;
		}

	}
};