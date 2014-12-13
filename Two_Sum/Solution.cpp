/**
* Created by Yu(Khitan) Wu on 12/13/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmial.com
*/
#include <unordered_map>
#include <utility>

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> hashmap;
		vector<int> result = { 0, 0 };

		for (size_t i = 0; i < numbers.size(); ++i){
			int diff = target - numbers[i];
			unordered_map<int, int>::const_iterator got = hashmap.find(diff);

			if (got == hashmap.end()) hashmap.insert(pair<int, int>(numbers[i], i));
			else{
				int temp1 = got->second + 1;
				int temp2 = i + 1;
				if (temp1 > temp2){ temp1 = i + 1; temp2 = got->second + 1; }
				result[0] = temp1; result[1] = temp2; // cannot use push_back here, vector needs to be initialized
				break;
			}
		}
		return result;
	}
};