#include <iostream>
#include <algorithm>

using namespace std;

class Stack {
private:
	int index;		//Arr[] index
	int size;		//Number of elements in the stack
	int capacity;	//Max capacity of stack
	int* arr;		//Array to store data

public:
	Stack(int val) {
		arr = new int[val];
		index = -1;
		size = 0;
		capacity = val;
	}

	~Stack() {
		delete[] arr;
	}

	void push(int val) {
		if (index + 1 == capacity) {
			cout << "Stack is full, cannot push more elements.\n";
			return;
		}
		arr[index] = val;
		index++;
	}

	void pop() {
		if (index == 0) {
			cout << "Stack is empty, cannot pop top.\n";
			return;
		}
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
