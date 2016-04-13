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

	/*
	 * Detect if a linked list is circular
	 *
	 * Input: 1->2->3->4->5
	 *              ^     |
	 *              |     V
	 *              -------
	 *
	 * Output: Linked list IS circular!
	 */

	Node* head = new Node(1);
	head->next = new Node(2);

	head->next->next = new Node(3);
	Node* circularHead = head->next->next; //End node links back to Node(3)

	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = circularHead; //End node links back

	if (detectCircularLL(head)) {
		cout << "List is circular!\n";
	} else {
		cout << "List is not circular!\n";
	}
}

bool detectCircularLL(Node* head) {

	Node* ptr1 = head, *ptr2 = head;

	while (ptr1->next != NULL) {
		ptr1 = ptr1->next;

		if (ptr2->next != NULL && ptr2->next->next != NULL) {
			ptr2 = ptr2->next->next;
		} else {
			return false; //There is an end
		}

		if (ptr1 == ptr2) {
			return true; //Is circular
		}
	}

	return false; //Else, 1 element list which is not circular

}
