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
Node* reverseList(Node*);
void printList(Node*);

int main() {

	Node *head = new Node(1);

	/* Fast populate linked list */
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);

	cout << "Original:\n";
	printList(head);

	Node* reversedList;
	reverseList(head, NULL, &reversedList);

	cout << "\n\nMethod 1 - Reversed:\n"; //Primitive
	printList(reversedList);

	cout << "\n\nMethod 2 - Reverse Back:\n"; //Better
	printList(reverseList(reversedList));

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

Node* reverseList(Node* itr) {

	Node* newHead, *nextNode; //Storage for after recursion hits base case
	if (itr->next != NULL) {
		nextNode = itr->next;
		newHead = reverseList(itr->next);
	} else {
		return itr;
	}

	nextNode->next = itr; //Node's original next = current
	itr->next = NULL; //Set new tail->next as null
	return newHead;
}

void printList(Node* itr) {

	if (itr != NULL) {
		cout << itr->data << " ";
		printList(itr->next);
	}
}
