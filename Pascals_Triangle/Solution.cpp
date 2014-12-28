/**
* Created by Yu(Khitan) Wu on 12/28/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> result;
		for (int length = 1; length <= numRows; ++length){
			vector<int> row;
			for (int j = 0; j < length; ++j){
				if (j == 0 || j == length - 1) row.push_back(1);
				else row.push_back(result[length - 2][j - 1] + result[length - 2][j]);
			}
			result.push_back(row);
		}
		return result;
	}
};