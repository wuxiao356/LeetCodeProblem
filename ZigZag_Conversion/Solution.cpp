/**
* Created by Yu(Khitan) Wu on 12/28/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1) return s;
		string result = "";
		// first row and last row have only one increment; the left rows have two increments
		//inc1 is the increment for the every row
		//inc2 is the increment for the left row
		int inc1 = 2 * nRows - 2, inc2 = 0, j = 0;
		for (int i = 0; i < nRows; ++i){
			inc2 = inc1 - 2 * i;
			int j = i;
			while (j < s.length()){
				result += s[j];
				if (i != 0 && i != nRows - 1 && j + inc2 < s.length()) result += s[j + inc2];
				j += inc1;
			}
		}
		return result;
	}
};