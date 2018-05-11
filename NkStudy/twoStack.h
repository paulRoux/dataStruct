#pragma once
#include <stack>
#include <iostream>

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
		
	}

	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				int tmp = stack1.top();
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		int tmp = stack2.top();
		stack2.pop();
		return tmp;
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};