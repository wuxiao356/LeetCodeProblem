/**
* Created by Yu(Khitan) Wu on 1/7/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int climbStairs(int n) {

		if (n == 1) { return 1; }
		else if (n == 2) { return 2; }
		else{
			int n1 = 1, n2 = 2, n3;
			for (int i = 3; i <= n; ++i){
				n3 = n1 + n2;
				n1 = n2;
				n2 = n3;
			}
			return n3;
		}
	}
};