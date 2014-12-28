/**
* Created by Yu(Khitan) Wu on 12/27/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	int compareVersion(string version1, string version2) {
		size_t dotPos1 = version1.find_first_of('.'), dotPos2 = version2.find_first_of('.');
		string sub1 = "", sub2 = "", emptyS = "";
		if (dotPos1 == string::npos) dotPos1 = version1.length();
		else sub1 = version1.substr(dotPos1 + 1, version1.length() - dotPos1 - 1);

		if (dotPos2 == string::npos) dotPos2 = version2.length();
		else sub2 = version2.substr(dotPos2 + 1, version2.length() - dotPos2 - 1);

		int first1 = 0, first2 = 0;
		if (dotPos1 != 0) first1 = stoi(version1.substr(0, dotPos1));
		if (dotPos2 != 0) first2 = stoi(version2.substr(0, dotPos2));

		if (first1 < first2) return -1;
		else if (first1 == first2) {
			if (sub1.compare(emptyS) == 0 && sub2.compare(emptyS) == 0) return 0;
			else return compareVersion(sub1, sub2);
		}
		else return 1;
	}
};