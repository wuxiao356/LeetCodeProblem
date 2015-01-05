/**
* Created by Yu(Khitan) Wu on 1/5/2015
* Copyright (C) 2015 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/
class Solution {
public:
	string addBinary(string a, string b) {
		int carry = 0;
		bool isALonger = false;
		int smallerLen = a.length();
		int biggerLen = b.length();
		if (a.length() > b.length()){
			smallerLen = b.length();
			biggerLen = a.length();
			isALonger = true;
		}
		string ans = "";
		for (int i = 0; i < smallerLen; ++i){
			if (a[a.length() - 1 - i] == '1' && b[b.length() - 1 - i] == '1') {
				if (carry == 0) { ans += '0'; carry = 1; }
				else{ ans += '1'; carry = 1; }
			}
			else if (a[a.length() - 1 - i] == '0' && b[b.length() - 1 - i] == '0'){
				if (carry == 0) ans += '0';
				else{ ans += '1'; carry = 0; }
			}
			else{
				if (carry == 0) ans += '1';
				else{ ans += '0'; carry = 1; }
			}
		}

		for (int i = smallerLen; i < biggerLen; ++i){
			if (isALonger){
				if (a[a.length() - 1 - i] == '1' && carry == 1){
					ans += '0'; carry = 1;
				}
				else if (a[a.length() - 1 - i] == '0' && carry == 0){
					ans += '0';
				}
				else{ ans += '1'; carry = 0; }
			}
			else{
				if (b[b.length() - 1 - i] == '1' && carry == 1){
					ans += '0'; carry = 1;
				}
				else if (b[b.length() - 1 - i] == '0' && carry == 0){
					ans += '0';
				}
				else{ ans += '1'; carry = 0; }
			}
		}
		if (carry == 1) ans += '1';
		//reverse ans
		string sum = "";
		for (int i = 0; i < ans.length(); ++i){
			sum += ans[ans.length() - 1 - i];
		}
		return sum;
	}
};