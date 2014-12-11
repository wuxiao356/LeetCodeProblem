class Solution {
public:
	bool isPalindrome(string s) {
		int length = s.length();
		bool result = true;
		int front = 0;
		int back = length - 1;

		if (length == 0) return true;
		else{
			while (front < back){
				while (!isalnum(s[front])){
					++front;
					if (front == length - 1) return true;
				}
				while (!isalnum(s[back])){
					--back;
					if (back == 0) return true;
				}
				char f = tolower(s[front]);
				char b = tolower(s[back]);
				if (f != b) { result = false; break; }
				++front;
				--back;
			}
		}
		return result;
	}
};