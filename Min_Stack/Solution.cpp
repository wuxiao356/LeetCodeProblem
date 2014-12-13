/**
* Created by Yu(Khitan) Wu on 12/11/2014
* Copyright (C) 2014 Yu(Khitna) Wu All rights reserved.
* Email: wuxiao356@gmail.com
*/

#include <stack>

class MinStack {
public:
	void push(int x) {
		element.push(x);
		if (minElement.empty()) minElement.push(x);
		else if (minElement.top() >= x) minElement.push(x);
	}

	void pop() {
		if (minElement.top() == element.top()) minElement.pop();
		element.pop();
	}

	int top() {
		return element.top();
	}

	int getMin() {
		return minElement.top();
	}

private:
	stack<int> element; // regular stack which is used to store the elements
	stack<int> minElement; //minimun stack which is used to store the minimum element in the past. That it, when the new element being                            //pushed is a new minimum, push it to the minElement too
};