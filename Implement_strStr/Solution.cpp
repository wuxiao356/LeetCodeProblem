/**
* Created by Yu(Khitan) Wu on 1/5/2015
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
		char *head = needle;

		for (int i = 0; i < haystackLength - needleLength + 1; ++i){
			if (haystack[i] == *head){
				bool found = true;
				++i; ++head;
				while (*head != '\0'){
					if (haystack[i] != *head) { found = false; break; }
					else { ++i; ++head; }
				}
				i -= (head - needle);
				if (found) return i;
				else { head = needle; }
			}
		}
		return -1;
	}
};