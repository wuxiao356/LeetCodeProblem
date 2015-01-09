/**
* Created by Yu(Khitan) Wu on 1/7/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		//check rows
		for (int i = 0; i < 9; ++i){
			int a[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			for (int j = 0; j < 9; ++j){
				int num = board[i][j] - '1';
				if (num >= 0 && num < 9 && a[num] == 0) a[num] = 1;
				else if (num >= 0 && num < 9 && a[num] == 1) return false;
			}
		}
		//check columns
		for (int i = 0; i < 9; ++i){
			int a[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			for (int j = 0; j < 9; ++j){
				int num = board[j][i] - '1';
				if (num >= 0 && num < 9 && a[num] == 0) a[num] = 1;
				else if (num >= 0 && num < 9 && a[num] == 1) return false;
			}
		}
		//check sub-boxes
		for (int j = 0; j < 3; ++j){
			for (int i = 0; i < 3; ++i){
				int a[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				for (int y = 0; y < 3; ++y){
					for (int x = 0; x < 3; ++x){
						int num = board[y + 3 * i][x + 3 * j] - '1';
						if (num >= 0 && num < 9 && a[num] == 0) a[num] = 1;
						else if (num >= 0 && num < 9 && a[num] == 1) return false;
					}
				}
			}
		}
		return true;
	}
};