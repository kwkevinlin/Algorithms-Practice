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

int findNextLargest(int);

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
	 */

	Node* head = new Node(5);
	head->left = new Node(6);
	head->left->left = new Node(3);
	head->left->left->right = new Node(1);
	head->left->right = new Node(9);
	head->right = new Node(4);
	head->right->left = new Node(8);
	head->right->right = new Node(2);

	cout << "Next largest number: " << findNextLargest(6);

}

int findNextLargest(int findThis) {


}
