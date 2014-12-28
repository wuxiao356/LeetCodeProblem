/**
* Created by Yu(Khitan) Wu on 12/27/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	string convertToTitle(int n) {
		string result = "";
		while (n) {
			string temp = string(1, char((n - 1) % 26 + 'A'));
			result = temp + result;
			n = (n - 1) / 26;
		}
		return result;
	}
};