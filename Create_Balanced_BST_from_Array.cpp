#include <iostream>

using namespace std;

struct Node;
Node* buildTree(int[], int, int);
void printTree(Node*);

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

int main() {

	/*
	 * Given an array with unique integer elements, write an
	 * algorithm to create a binary search tree with minimal
	 * height.
	 *
	 * Adapted from Cracking the Coding Interview
	 * Chapter 4, Question 3
	 *
	 */

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	Node* head = buildTree(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);

	//Check build with prefix printout
	printTree(head);

}

Node* buildTree(int arr[], int start, int end) {

	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;

	Node* newNode = new Node(arr[mid]);

	newNode->left = buildTree(arr, start, mid-1);
	newNode->right = buildTree(arr, mid+1, end);

	return newNode;
}

void printTree(Node* itr) {

	cout << itr->data << " ";

	if (itr->left != NULL) {
		printTree(itr->left);
	}
	if (itr->right != NULL) {
		printTree(itr->right);
	}
}
