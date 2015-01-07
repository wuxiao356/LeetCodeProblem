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

		int thash = 0;
		int phash = 0;
		const int charNum = 256; // number of characters in ASCII
		const int prime = 4049;
		int h = 1;

		for (int i = 0; i < needleLength - 1; ++i){
			h = (h * charNum) % prime;
		}

		for (int i = 0; i < needleLength; ++i){
			phash = (charNum * phash + needle[i]) % prime;
			thash = (charNum * thash + haystack[i]) % prime;
		}

		for (int i = 0; i <= haystackLength - needleLength; ++i){
			if (thash == phash){
				int j = 0;
				for (; j < needleLength; ++j){
					if (haystack[i + j] != needle[j]) break;
				}
				if (j == needleLength) return i;
			}

			if (i < haystackLength - needleLength){
				thash = (charNum*(thash - h * haystack[i]) + haystack[i + needleLength]) % prime;
				if (thash < 0) thash = thash + prime;
			}
		}
		return -1;
	}
};