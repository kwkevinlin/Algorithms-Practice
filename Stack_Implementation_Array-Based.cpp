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
		index++;
		size++;
		arr[index] = val;
	}

	void pop() {
		if (index < 0) {
			cout << "Stack is empty, cannot pop more elements.\n";
			return;
		}
		index--;
		size--;
	}

	int top() {
		if (index == -1) {
			cout << "Stack is empty. Returning -1.\n";
			return -1;
		}
		return arr[index];
	}

	int getSize() {
		return size;
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

	Stack myStack(5);

	//Push 5 elements
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);

	//Out of bounds, will return error
	myStack.push(6);

	//Pop remaining 5 elements
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();

	//Out of bounds, will return error
	myStack.pop();

	//Get number of elements in stack
	cout << "Size: " << myStack.getSize() << endl;

	//Bool isEmpty
	cout << "Empty: " << (myStack.isEmpty() ? "true" : "false") << endl;

	//Push new elements
	myStack.push(15);
	myStack.push(20);

	//Traverse and pop through stack
	while(!myStack.isEmpty()) {
		cout << myStack.top() << endl;
		myStack.pop();
	}
}
