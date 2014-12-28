/**
* Created by Yu(Khitan) Wu on 12/28/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int atoi(const char *str) {
		// string contains invalid character like * g 
		// how to deal with the case when string has decimal part
		// how to deal with the case when string has an integer which is overflow
		// how to deal with the case when string begins with whitespace
		int digits = 0, result = 0;
		bool isPos = true;

		while (str[digits] == ' ' || str[digits] == '0') ++digits; //get rid of whitespace and 0
		int i = digits;
		if (str[digits] == '-') { ++digits; ++i; isPos = false; }
		else if (str[digits] == '+'){ ++digits; ++i; }

		while (str[digits] - '0' <= 9 && str[digits] - '0' >= 0){ ++digits; }

		while (i < digits){
			int temp = result + (str[i] - '0') * pow(10, digits - i - 1);
			// overflow
			if (temp < result){
				if (isPos) result = INT_MAX;
				else result = INT_MIN;
				return result;
			}
			result = temp;
			++i;
		}
		if (!isPos) result = 0 - result;
		return result;
	}

};