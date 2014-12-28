/**
* Created by Yu(Khitan) Wu on 12/28/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int titleToNumber(string s) {
		int i = s.length();
		int result = 0;
		while (i >= 1){
			result += (s[i - 1] - 'A' + 1) * pow(26, s.length() - i);
			--i;
		}
		return result;
	}
};