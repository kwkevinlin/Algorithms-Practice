#include <iostream>

using namespace std;

/* Node declaration in single file for simplicity */
struct Node
{
	int data;
	Node* next;

	Node(int n) {
		data = n;
		next = NULL;
	}
};

void reverseList(Node*);

int main() {

	Node *head = new Node(1);

	/* Populate list without linked list class */
	head->next = new Node(2);
	head->next->next = new Node(2);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);

	reverseList(head);
}