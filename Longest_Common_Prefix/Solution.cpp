/**
 * Created by Yu(Khitan) Wu on 12/11/2014
<<<<<<< HEAD
 * Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
 * Email: wuxiao356@gmial.com
=======
 * Copyright (C) 2014 Yu(Khitna) Wu All rights reserved.
 * Email: wuxiao356@gmail.com
>>>>>>> origin/master
 */
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string LCP;
		if (strs.size() == 0) return LCP;
		bool hasNext = true;
		int j = 0;
		while (hasNext){
			if (strs[0].size() <= j) return LCP;
			char commonChar = strs[0][j];
			int numOfCommon = 1;
			for (int i = 1; i < strs.size(); ++i){
				if (strs[i].size() <= j) { hasNext = false; break; }
				else if (strs[i][j] != commonChar) { hasNext = false; break; }
				else ++numOfCommon;
			}
			if (numOfCommon == strs.size()) { LCP += commonChar; ++j; }
		}

		return LCP;
	}
};
