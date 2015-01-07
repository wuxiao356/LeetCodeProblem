/**
* Created by Yu(Khitan) Wu on 1/7/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (haystack == NULL || needle == NULL) return 0;
		if (*needle == '\0') return 0;
		int haystackLength = strlen(haystack);
		int needleLength = strlen(needle);
		if (needleLength > haystackLength) return -1;

		for (int i = 0; i <= haystackLength - needleLength + 1; ++i){
			int j = 0;
			for (; j < needleLength; ++j){
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == needleLength) return i;

		}
		return -1;
	}
};