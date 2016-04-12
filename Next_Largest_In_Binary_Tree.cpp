#include <iostream>
#include <vector>
#include <algorithm>

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
void DFSToVec(Node*, vector<int> &);

int main() {

	/*
	 * Given a node in a binary tree, find the next
	 * largest integer in the tree.
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
	 *     DFS traverse the tree and store each element
	 *     into a vector. Then, sort the vector and find
	 *     the index of the current node, then return
	 *     the index of current node + 1 to return the
	 *     next largest element in the tree.
	 *
	 * Complexity of Approach 1:
	 *     O(nlogn) for sorting the vector
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

	cout << "Next largest integer: " << findNextLargest(head, 6);

}

int findNextLargest(Node* head, int findThis) {

	//Traverse via DFS (using inOrder here), and return data into vector
	vector<int> treeVec;
	DFSToVec(head, treeVec);

	//Sort vector containing tree nodes
	sort(treeVec.begin(), treeVec.end());

	for (int i = 0; i < treeVec.size(); i++) {
		if (treeVec[i] == findThis) {
			if (i + 1 < treeVec.size()) {
				return treeVec[i+1];
			} else {
				cout << "Error: No larger integer!\n";
				exit(1);
			}

		}
	}

	cout << "Input (" << findThis << ") not found!\n";
	exit(1);
}

void DFSToVec(Node* itr, vector<int> & treeVec) {

	if (itr->left != NULL) {
		DFSToVec(itr->left, treeVec);
	}

	treeVec.push_back(itr->data);

	if (itr->right != NULL) {
		DFSToVec(itr->right, treeVec);
	}

}
