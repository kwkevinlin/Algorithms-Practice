#include <iostream>

using namespace std;

struct Node {

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

int kthToLast1(Node*, int); //Approach 1
int kthToLast2(Node*, int); //Approach 2

int main() {

	/*
	 * Find the Kth element from the end of a linked list.
	 *
	 * For example:
	 * 	   List: 1 -> 2 -> 3 -> 4 -> 5
	 * 	   K = 2
	 * 	   Output: 4
	 *
	 * Two approaches; both are linear time.
	 *
	 */

	//Quick list setup
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	int kth = 2;

	/*
	 * Approach 1: (worst)
	 * If size of list is known. If not, traverse through the list in O(n) time to retrieve size.
	 */
	int listSize = 5;
	cout << "Method 1:\nKth to last: " << kthToLast1(head, (listSize - kth)) << endl;

	/*
	 * Approach 2: (best)
	 * Create two pointers, and point the second pointer to K elements into the node. Then, increment
	 * both pointers by 1 element until the second pointer reaches the end of list. First pointer will
	 * be at the position of the Kth to last element.
	 */
	cout << "\nMethod 2:\nKth to last: " << kthToLast2(head, kth) << endl;


}

int kthToLast1(Node* node, int kth) {

	if (kth == 0) {
		return node->data;
	} else if (node->next != NULL){
		kthToLast1(node->next, kth - 1);
	} else {
		cout << "K is greater than the number of elements in the list!\nError: Returning -1\n\n";
		return -1;
	}

}

int kthToLast2(Node* head, int kth) {

	Node* ptr1 = head;
	Node* ptr2 = head;

	//Moving ptr2 K elements forward
	for (int i = 0; i < kth - 1; i++) { //Notice -1, because (ex) 2nd to last means the one RIGHT NEXT to last (so dist = 1)
		if (ptr2->next != NULL) {
			ptr2 = ptr2->next;
		} else {
			cout << "K is greater than the number of elements in the list!\nError: Returning -1\n\n";
			return -1;
		}
	}

	//Traverse both pointers
	while (ptr2->next != NULL) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	//Ptr1 will be at Kth to last element
	return ptr1->data;

}
