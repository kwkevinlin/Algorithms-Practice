#include <iostream>

using namespace std;

/* Node declaration in single file for simplicity */
struct Node
{
	int data;
	Node* next;

	Node() {
		data = -1;
		next = NULL;
	}
	Node(int n) {
		data = n;
		next = NULL;
	}
};

void reverseList(Node*, Node*, Node**);

int main() {

	Node *head = new Node(1);

	/* Populate list without linked list class */
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);

	Node* reversedList;
	reverseList(head, NULL, &reversedList); //Passing reversedList by reference to update head

	cout << "Rev: " << reversedList->data << endl;
}

void reverseList(Node* current, Node* prev, Node** head) {

	if (current->next == NULL) { //If last element
		*head = current; //Update head
	} else {
		reverseList(current->next, current, head);
	}

	//Tail recursion returns
	current->next = prev;

}
