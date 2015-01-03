/**
* Created by Yu(Khitan) Wu on 1/3/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	string countAndSay(int n) {
		string start = "1";
		if (n == 1) return start;
		string ans = "";
		for (int i = 2; i <= n; ++i){
			ans = "";
			char c = start[0];
			int count = 1;
			for (int i = 1; i < start.length(); ++i){
				if (start[i] == c) ++count;
				else{
					ans += ('0' + count);
					ans += c;
					c = start[i];
					count = 1;
				}
			}
			ans += ('0' + count);
			ans += c;
			start = ans;
		}
		return ans;
	}
};