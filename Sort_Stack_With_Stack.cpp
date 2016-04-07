#include <iostream>
#include <stack>

using namespace std;

int longestIncSubseq(int[], int);

int main() {

	/*
	 * Write a program to sort a stack in ascending order (biggest
	 * items on top). You may use at most one additional stack to
	 * hold items, but you may not copy the elements into any other
	 * data structure.
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

	stack<int> stack2;

	//So stack2 already has an element
	int tmp = stack1.top();
	stack1.pop();

	//While stack1 still has elements
	while (stack1.empty() != true) {
		if (stack1.top() > stack2.top()) {
			//Move stack1 element to stack2
			tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		} else {
			/*  Pop stack1.top in another var temp, then push every
				element greater than temp in stack2 onto stack1. Then,
				push temp into stack2.  */

		}
	}

}
