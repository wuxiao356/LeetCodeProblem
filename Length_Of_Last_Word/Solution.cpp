/**
* Created by Yu(Khitan) Wu on 1/7/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (s == NULL) return 0;
		int length = 0, lastWordLength = 0;
		int i = 0;
		while (s[i] != '\0'){
			if (s[i] != ' ') ++length;
			else{
				if (length != 0) lastWordLength = length;
				length = 0;
			}
			++i;
		}
		if (length != 0) return length;
		return lastWordLength;
	}
};