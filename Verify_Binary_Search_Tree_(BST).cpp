#include <iostream>
#include <vector>

using namespace std;

struct Node;
bool verifyBST(Node*);
void verifyBST(Node*, vector<int>&);

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

	/* Verify is a tree is a Binary Search Trees (BST)

		          Tree
		           10
		          /   \
		        5     15
		       /  \
		     2    7

	  Solution:
	      In order traverse the tree. If in order
	      traversal is in sorted order, then tree is a BST.

	*/

	Node* tree = new Node(10);
	tree->left = new Node(5);
	tree->right = new Node(15);
	tree->left->left = new Node(2);
	tree->left->right = new Node(7);

	if (verifyBST(tree)) {
		cout << "Tree is a BST!\n";
	} else {
		cout << "Tree is NOT a BST!\n";
	}

}

bool verifyBST(Node* head) {
	if (head->left != NULL || head->right != NULL) {
		vector<int> inOrderArr;
		verifyBST(head, inOrderArr);

		bool isBST = true;

		//Check if inOrderArr is in sorted order
		for (int i = 1; i < inOrderArr.size(); i++) {
			if (inOrderArr[i] < inOrderArr[i-1]) {
				isBST = false;
				break;
			}
		}

		return isBST;

	} else { //Only one element is still BST
		return true;
	}
}

void verifyBST(Node* itr, vector<int>& inOrderArr) {
	//Read in inOrder and store into inOrderArr

	if (itr->left != NULL) {
		verifyBST(itr->left, inOrderArr);
	}

	inOrderArr.push_back(itr->data);

	if (itr->right != NULL) {
		verifyBST(itr->right, inOrderArr);
	}

}
