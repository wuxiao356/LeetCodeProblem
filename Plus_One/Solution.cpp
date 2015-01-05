/**
* Created by Yu(Khitan) Wu on 1/5/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		for (int i = 0; i < digits.size(); ++i){
			if (digits[digits.size() - 1 - i] == 9 && carry == 1){
				carry = 1; digits[digits.size() - 1 - i] = 0;
			}
			else if (digits[digits.size() - 1 - i] < 9 && carry == 1){
				digits[digits.size() - 1 - i] += 1; carry = 0;
			}
			else{
				return digits;
			}
		}
		if (carry == 1){
			digits.push_back(1);
			for (int i = digits.size() - 1; i >= 1; --i){
				int temp = digits[i - 1];
				digits[i - 1] = digits[i];
				digits[i] = temp;
			}
		}
		return digits;
	}
};