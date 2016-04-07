#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>, stack<int>&);

int main() {

	/*
	 * Write a program to sort a stack in ascending order (biggest
	 * items on top). You may use at most one additional stack to
	 * hold items, but you may not copy the elements into any other
	 * data structure.
	 *
	 * Solution:
	 *     If stack1.top > stack2.top, push stack1.top into stack2.top.
	 *     Else, store stack1.top into a tmp variable, then push every
	 *     element on stack2 > tmp to stack1. Then, push tmp onto stack2.
	 *     Repeat process until stack1 is empty.
	 *
	 * Complexity:
	 *     Time: O(n^2)
	 *     Space: O(n)
	 *
	 * Adapted from Cracking the Coding Interview
	 * Chapter 3, Question 6
	 *
	 */

	stack<int> stack1;
	stack1.push(5);
	stack1.push(3);
	stack1.push(7);
	stack1.push(1);

	stack<int> result;
	sortStack(stack1, result);

	//Print results
	while (result.empty() != true) {
		cout << result.top() << " ";
		result.pop();
	}

}

void sortStack(stack<int> stack1, stack<int> &result) {

	int tmp;

	//Populate result stack with top element of stack1
	result.push(stack1.top());
	stack1.pop();

	//While stack1 still has elements
	while (stack1.empty() != true) {
		if (stack1.top() >= result.top()) {
			//Move stack1 element to result
			result.push(stack1.top());
			stack1.pop();
		} else {
			/*  Pop stack1.top in tmp, then push every
					element greater than tmp in result onto stack1. Then,
					push tmp into result.  */
			tmp = stack1.top();
			stack1.pop();
			while (result.empty() != true) {
				if (result.top() > tmp) {
					stack1.push(result.top());
					result.pop();
				} else {
					break;
				}
			}
			result.push(tmp);
		}
	}

}
