/**
* Created by Yu(Khitan) Wu on 12/13/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
#include <stack>

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) return true;
		else if (s.length() % 2 == 1) return false;

		stack<char> leftPs;
		for (int i = 0; i < s.length(); ++i){
			char p = s[i];
			if (p == '(' || p == '{' || p == '[') leftPs.push(p);
			else if (leftPs.empty()) return false;
			else if (isMatched(p, leftPs.top())) leftPs.pop();
			else return false;
		}

		if (leftPs.empty()) return true;
		else return false;
	}

	bool isMatched(char right, char left){
		if (left == '[' && right == ']' ||
			left == '(' && right == ')' ||
			left == '{' && right == '}') return true;
		else return false;
	}
};