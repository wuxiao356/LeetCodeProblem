/**
* Created by Yu(Khitan) Wu on 1/4/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int trailingZeroes(int n) {
		if (n < 5) return 0;
		int x = log(n) / log(5);

		int ans = 0;
		for (int i = 1; i <= x; ++i){
			int m = n / pow(5, i);
			ans = ans + m;
		}
		return ans;
	}
};