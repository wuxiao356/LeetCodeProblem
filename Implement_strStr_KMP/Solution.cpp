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

		int *LSP = new int[needleLength];
		calculateLSP(LSP, needle, needleLength);
		int j = 0, i = 0;
		while (i < haystackLength){
			if (haystack[i] == needle[j]){ ++i; ++j; }
			if (j == needleLength) return i - j;
			if (i < haystackLength && haystack[i] != needle[j]){
				if (j != 0)j = LSP[j - 1];
				else ++i;
			}
		}
		delete[] LSP;
		return -1;
	}

	void calculateLSP(int *LSP, char *pattern, int patternLength){
		int len = 0;
		LSP[0] = 0;
		int i = 1;
		while (i < patternLength){
			if (pattern[i] == pattern[len]){
				++len;
				LSP[i] = len;
				++i;
			}
			else if (len != 0){
				len = LSP[len - 1];
			}
			else{ LSP[i] = 0; ++i; }
		}
	}
};