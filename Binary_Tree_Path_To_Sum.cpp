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

vector<Node*> findPath(Node*, int);
int findPathUtil(Node*, int);

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

	int sum = 19;

	findPath(tree1, sum);

}

vector<Node*> findPath(Node* itr, int sum) {

	vector<Node*> path;
	int currentSum;
	currentSum = findPathUtil(itr, sum);

	return path;
}

int findPathUtil(Node* itr, int sum) {

	//Base case
	if (itr->left == NULL && itr->right == NULL) {
		return itr->data;
	}

	int leftPath = 0, rightPath = 0;
	if (itr->left != NULL) {
		leftPath = itr->data + findPathUtil(itr->left, sum);
	}

	if (itr->right != NULL) {
		rightPath = itr->data + findPathUtil(itr->right, sum);
	}

	if (leftPath == sum) {
		cout << "Found a path\n";
		return leftPath;
	} else if (rightPath == sum) {
		cout << "Found a path\n";
	} else if (leftPath > sum) {
		return leftPath;
	} else if (rightPath > sum) {
		return 0;
	}

}
