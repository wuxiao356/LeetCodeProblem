/**
* Created by Yu(Khitan) Wu on 1/9/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
#include <algorithm>
class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {

		sort(num.begin(), num.end());
		int repeat = num[0];
		int result = num[0] + num[1] + num[2];
		int smallestDiff = abs(result - target);
		for (int i = 0; i < num.size() - 2; ++i){
			if (i > 0 && num[i] == repeat) continue;
			repeat = num[i];
			int tempSum = num[i] + twoSumClosest(num, target - num[i], i + 1, num.size() - 1);

			if (tempSum == target) return target;
			else if (abs(tempSum - target) < smallestDiff){ smallestDiff = abs(tempSum - target); result = tempSum; }
			else continue;
		}
		return result;
	}

	int twoSumClosest(vector<int> &num, int target, int begin, int end){
		int result = num[begin] + num[end];
		int smallestDiff = abs(result - target);
		while (begin < end){
			int tempSum = num[begin] + num[end];

			if (tempSum == target){
				return target;
			}
			else if (tempSum < target){
				if (abs(tempSum - target) < smallestDiff){ smallestDiff = abs(tempSum - target); result = tempSum; }
				++begin;
			}
			else{
				if (abs(tempSum - target) < smallestDiff){ smallestDiff = abs(tempSum - target); result = tempSum; }
				--end;
			}
		}
		return result;
	}
};