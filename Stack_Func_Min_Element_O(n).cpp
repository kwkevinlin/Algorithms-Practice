#include <iostream>
#include <limits>
#include <cstdlib>
#include <time.h>

using namespace std;

class myStack {
public:
	myStack() {
		dataStkIndex = 0;
		minStkIndex = 0;
		min = numeric_limits<int>::max();
	}

	void push(int n) {
		dataStk[dataStkIndex] = n;
		dataStkIndex++;
		if (n <= min) {
			min = n;
			minStk[minStkIndex] = n;
			minStkIndex++;
		}
	}
	void pop() {
		if (dataStk[dataStkIndex-1] == minStk[minStkIndex-1]) {
			minStkIndex--;
			min = minStk[minStkIndex-1];
		}
		dataStkIndex--;
	}
	int getMin() {
		if (minStkIndex == -1) {
			cout << "Stack empty; no minimum. Returning -1. ";
			return -1;
		}
		return minStk[minStkIndex-1];
	}
	int top() {
		return dataStk[dataStkIndex-1];
	}
	void printMinStk() {
		for (int i = 0; i < minStkIndex; i++) {
			cout << "|" << minStk[i] << "|\n";
		}
	}

private:
	int dataStkIndex, minStkIndex, min;
	int dataStk[10];
	int minStk[10];

};

int main() {

	/*
	 * Question: How would you design a stack which, in addition to push and pop, also has
	 * 			 a function min which returns the minimum element? Push, pop and min should
	 * 			 all operate in O(1) time.
	 *
	 * Solution: Uses two stacks to keep track of data and minimum value. Sacrifices some
	 * 			 space complexity to get O(1) times for all three operations.
	 *
	 * Caveat:   For simplicity, stack is implemented with fixed size arrays. Also, further
	 * 			 optimization can be done to reduce space complexity (ie. do not store
	 * 			 duplicate elements).
	 *
	 * Complexity: O(1) for all three operations.
	 *
	 * Adapted from Cracking The Coding Interview: Chapter 3, Question 2
	 *
	 */

}