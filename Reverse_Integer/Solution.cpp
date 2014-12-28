/**
* Created by Yu(Khitan) Wu on 12/28/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int reverse(int x) {
		int intermediate = x;
		if (x < 0) intermediate = 0 - intermediate;
		int result = 0;
		int digits = log10(intermediate);

		while (intermediate != 0){
			int m = intermediate % 10;
			int temp = result + m * pow(10, digits);
			// this is the overflow case
			if (temp < result) return 0;
			result = temp;
			--digits;
			intermediate = intermediate / 10;
		}

		if (x < 0) result = 0 - result;
		return result;
	}
};