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

int kthToLast(Node*, int);

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

	int kth = 6;

	/*
	 * Approach 1: (worst)
	 * If size of list is known. If not, traverse through the list in O(n) time to retrieve size.
	 */
	int listSize = 5;
	cout << "Kth to last: " << kthToLast(head, (listSize - kth)) << endl;

	/*
	 * Approach 2: (best)
	 * Create two pointers, and point the second pointer to K elements into the node. Then, increment
	 * both pointers by 1 element until the second pointer reaches the end of list. First pointer will
	 * be at the position of the Kth to last element.
	 */


}

int kthToLast(Node* node, int kth) {

	if (kth == 0) {
		return node->data;
	} else if (node->next != NULL){
		kthToLast(node->next, kth - 1);
	} else {
		cout << "K is greater than the number of elements in the list!\nError: Returning -1\n\n";
		return -1;
	}

}
