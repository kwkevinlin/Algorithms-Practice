#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

int getMin(Node*);

int main () {

	/*
	 * Find the minimal path from head to leaf
	 *
	 *      Tree
	 *       10
	 *     5    3
	 *   2   1    6
	 *    3
	 *
	 * Complexity: O(n), essentially DFS
	 * (Note: Add comments!)
	 */

	Node* tree1 = new Node(10);
	tree1->left = new Node(5);
	tree1->left->left = new Node(2);
	tree1->left->left->right = new Node(3);
	tree1->left->right = new Node(1);
	tree1->right = new Node(3);
	tree1->right->right = new Node(6);

	cout << getMin(tree1);

}

int getMin(Node* itr) {

	if (itr->left == NULL && itr->right == NULL) {
		return itr->data;
	}

	int left = 0, right = 0;

	if (itr->left != NULL) {
		left = itr->data + getMin(itr->left);
	}

	if (itr->right != NULL) {
		right = itr->data + getMin(itr->right);
	}

	if (left >= right) {
		if (right != 0) {
			return right;
		} else {
			return left;
		}
	} else {
		if (left != 0) {
			return left;
		} else {
			return right;
		}
	}

}
