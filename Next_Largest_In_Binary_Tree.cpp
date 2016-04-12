#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node() {
		data = -1;
		left = NULL;
		right = NULL;
	}

	Node(int num) {
		data = num;
		left = NULL;
		right = NULL;
	}
};

int findNextLargest(Node*, int);
void inOrderToVec(Node*, vector<int> &);

int main() {

	/*
	 * Given a node in a binary tree, find the next
	 * largest number in that tree.
	 *
	 * Example Binary Tree:
	 *
	 *           5
	 *        /     \
	 *       6       4
	 *      / \     / \
	 *     3   9   8   2
	 *      \
	 *       1
	 *
	 * Approach 1:
	 *     InOrder traverse the tree, then store every
	 *     element into an array. Find the element you
	 *     are given, then return the index of that
	 *     element + 1 to get the index of the next
	 *     largest integer.
	 *
	 * Complexity of Approach 1:
	 *     O(n) for InOrder traversal
	 *
	 */

	Node* head = new Node(5);
	head->left = new Node(6);
	head->left->left = new Node(3);
	head->left->left->right = new Node(1);
	head->left->right = new Node(9);
	head->right = new Node(4);
	head->right->left = new Node(8);
	head->right->right = new Node(2);

	cout << "Next largest number: " << findNextLargest(head, 6);

}

int findNextLargest(Node* head, int findThis) {

	//Traverse via InOrder, and return data into vector
	vector<int> inOrder;
	inOrderToVec(head, inOrder);

}

void inOrderToVec(Node* itr, vector<int> & inOrder) {

	if (itr->left != NULL) {
		inOrderToVec(itr->left, inOrder);
	}

	inOrder.push_back(itr->data);

	if (itr->right != NULL) {
		inOrderToVec(itr->right, inOrder);
	}


}
