#include <iostream>
#include <vector>

using namespace std;

bool isSubtree(struct Node*, Node*);
void parseToVector(Node*, vector<Node*>&);

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

	/* Merging two Binary Search Trees (BST)

	          Tree 1         Subtree of 1
	           100               50
	          /   \             /  \
	        50    300         20    70
	       /  \
	     20    70

	   Approach:
	   Read both trees via preOrder (to retain structure) into two vectors, then
	   check if vector 2 (subtree) is contained in vector 1 (tree 1).

	   Note:
	   There might be a more efficient algorithm, but I'll start with this one.

	 */

	//Creating trees manually for simplicity
	Node* tree1 = new Node(100);
	tree1->left = new Node(50);
	tree1->right = new Node(300);
	tree1->left->left = new Node(20);
	tree1->left->right = new Node(70);

	Node* tree2 = new Node(50);
	tree2->left = new Node(20);
	tree2->right = new Node(70);

	if (isSubtree(tree1, tree2)) {
		cout << "Tree 2 is a subtree\n";
	} else {
		cout << "Tree 2 is NOT a subtree\n";
	}

}

bool isSubtree(Node* tree1, Node* tree2) {

	//Parse via PreOrder fashion
	vector<Node*> vecTree1;
	vector<Node*> vecTree2;
	parseToVector(tree1, vecTree1);
	parseToVector(tree2, vecTree2);

	//Check vectors
	cout << "vecTree1\n";
	for (int i = 0; i < vecTree1.size(); i++) {
		cout << vecTree1[i]->data << " ";
	}
	cout << "\nvecTree1\n";
	for (int i = 0; i < vecTree2.size(); i++) {
		cout << vecTree2[i]->data << " ";
	}

	/*
	 * Traverse vecTree1. If [i]->data == head of subtree, then check
	 * subsequent values to see if they are identical. If yes, then
	 * isSubtree is true. Else, false.
	 *
	 * Potential Issues:
	 * What if the trees look like:
	 *
	 *         Tree 1      Tree 2 (SubTree)
	 *          100              50
	 *       50    300         20  70
	 *     20  70
	 *   10 40
	 *
	 * Notice the two extra child of 20
	 *    Current algorithm will still verify Tree 2 as subtree even
	 *    though it's just "a part of" the subtree.
	 *
	 */


	return false;
}

void parseToVector(Node* tree, vector<Node*> &vecTree) {

	//Via PreOrder approach
	vecTree.push_back(tree);

	if (tree->left != NULL) {
		parseToVector(tree->left, vecTree);
	}

	if (tree->right != NULL) {
		parseToVector(tree->right, vecTree);
	}

}
