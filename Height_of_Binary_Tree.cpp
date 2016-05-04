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

	Node(int n) {
		data = n;
		left = NULL;
		right = NULL;
	}
};

int getHeight(Node*);

int main() {

	/*
	 * Return the height of a binary tree given the head.
	 *
	 *         Tree
	 *          10
	 *        /    \
	 *       5      15
	 *      / \
	 *     2   7
	 */

	Node* head = new Node(10);
	head->left = new Node(5);
	head->right = new Node(15);
	head->left->left = new Node(2);
	head->left->right = new Node(7);

	cout << "Height: " << getHeight(head) << endl;
}

int getHeight(Node* head) {

	//Leaf node base case
	if (head->left == NULL && head->right == NULL) {
		return 1;
	}

	//Get height of left and right subtree
	int left = -1, right = -1;
	if (head->left != NULL) {
		left = 1 + getHeight(head->left);
	}

	if (head->right != NULL) {
		right = 1 + getHeight(head->right);
	}

	//Return longest height only
	if (left > right) {
		return left;
	} else {
		return right;
	}
}
