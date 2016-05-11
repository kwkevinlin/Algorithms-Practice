#include <iostream>

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

int main () {

	/*
	 * Given a binary tree and a sum, find all the paths that leads to the sum.
	 *
	 *     Tree
	 *      10
	 *    5    3
	 *  2   7    6
	 */

	Node* tree1 = new Node(10);
	tree1->left = new Node(5);
	tree1->right = new Node(3);
	tree1->left->left = new Node(2);
	tree1->left->right = new Node(7);
	tree1->right->right = new Node(6);

}
