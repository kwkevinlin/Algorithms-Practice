#include <iostream>

using namespace std;

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

bool detectCircularLL(Node*);

int main() {

	Node* head = new Node(1);
	head->next = new Node(2);

	head->next->next = new Node(3);
	Node* circularHead = head->next->next; //End node links back to Node(3)

	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = circularHead; //End node links back

	if (detectCircularLL(head)) {
		cout << "Linked list IS circular!\n";
	} else {
		cout << "Linked list is NOT circular!\n";
	}
}

bool detectCircularLL(Node* head) {

	

}
