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
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x == 0) return true;

		int numOfDigits = floor(log10(x));
		bool result = true;
		while (numOfDigits > 0){
			int end = x % 10;
			int front = x / pow(10, numOfDigits);
			if (end != front) { result = false; break; }

			x = x / 10; --numOfDigits;
			x = x - front * pow(10, numOfDigits); --numOfDigits;
		}

		return result;
	}
};
