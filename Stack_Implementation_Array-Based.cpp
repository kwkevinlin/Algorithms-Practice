#include <iostream>
#include <algorithm>

using namespace std;

class Stack {
private:
	int index;
	int size;
	int* arr;

public:
	Stack(int size) {
		arr = new int[size];
		index = -1;
		size = 0;
	}

	void push(int val) {
		arr[index] = val;
		index++;
	}

	void pop() {
		index--;
	}

	int top() {
		return arr[index];
	}

	bool isEmpty() {
		if (size > 0) {
			return false;
		} else {
			return true;
		}
	}

};

int main() {

	/*
	 * Implementation of an array-based stack.
	 */


}
