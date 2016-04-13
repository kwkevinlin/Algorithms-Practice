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

	/* Populate list without linked list class */
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
	reverseList(head, NULL, &reversedList); //Passing reversedList by reference to update head

	cout << "\n\nMethod 1 - Reversed:\n";
	printList(reversedList);

	cout << "\n\nMethod 2 - Reversed:\n";
	printList(reverseList(head));
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

Node* reverseList(Node* head) {

	//End of list base case
	if (head->next == NULL || head == NULL) {
		return head;
	}

	Node* newHead = reverseList(head->next); //Recursively return new head (since base case is last)
	head->next->next = head; //Set next of next to become current node
	head->next = NULL; //Invalidate original next

	return newHead;
}

void printList(Node* itr) {

	cout << itr->data << " ";

	if (itr->next != NULL) {
		printList(itr->next);
	}
}
