/**
* Created by Yu(Khitan) Wu on 12/28/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row(rowIndex + 1, 1);
		for (int i = 0; i <= rowIndex; ++i){
			int temp1 = 1, temp2 = 1;
			if (i >= 1) temp2 = row[1];

			for (int j = 0; j <= i; ++j){
				if (j == 0 || j == i) continue;
				else {
					row[j] = temp1 + temp2;
					temp1 = temp2;
					temp2 = row[j + 1];
				}
			}
		}
		return row;
	}
};