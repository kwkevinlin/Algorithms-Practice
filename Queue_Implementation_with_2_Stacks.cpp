#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:

	Queue() {};

	void push_back(int data) {
		if (s1.size() != 0) { //Not empty
			while(s1.size() != 0) { //Put all s1 into s2
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(data);
			while(s2.size() != 0) { //Put s2 back to s1
				s1.push(s2.top());
				s2.pop();
			}
		} else { //Empty
			s1.push(data);
		}
	}
	void pop_front() {
		s1.pop();
	}
	bool empty() {
		//S2 should always be empty outside of push_back()
		if (s1.empty())
			return true;
		else
			return false;
	}
	int size() {
		return s1.size();
	}
	void printQueueEndProgram() {
		while (s1.size() != 0) {
			cout << s1.top() << " ";
			s1.pop();
		}
	}

private:
	stack<int> s1;
	stack<int> s2;
};

int main () {

	/*
	 * Implementing a Queue with two Stacks
	 *
	 *		Approach:
	 * 			If stack 1 empty, push new element into stack. If stack 1 is not empty,
	 * 			push then pop (on stack 1) everything onto stack 2, then add (pop) new
	 * 			data into stack 1. Then, push then pop (from stack 2) everything back onto
	 * 			stack 1.
	 *
	 * 		Basic functionalities:
	 * 			push_back
	 * 			pop_front
	 * 			empty
	 * 			size
	 */

	Queue myQueue;

	myQueue.push_back(3); // 3
	myQueue.push_back(1); // 3 1
	myQueue.pop_front();  // 1
	myQueue.push_back(2); // 1 2
	myQueue.push_back(4); // 1 2 4
	myQueue.pop_front();  // 2 4

	cout << "Queue empty (T/F): " << (myQueue.empty() == 1 ? "T" : "F") << endl;
	cout << "Queue size: " << myQueue.size() << endl;

	/* printQueueEndProgram() prints everything in the "queue". However, in doing so, it
	   deletes everything in stack 1 (and stack 2 should already be empty) */
	cout << "\nElements in Queue:\n";
	myQueue.printQueueEndProgram();

}
