#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Node* mergeTree(Node*, Node*);
void toVector(Node*, vector<Node*>);

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

		     Tree 1           Tree 2
			  100				80
	          /  \			   /  \
	        50    300        40   120
	       / \
	      20  70
	 */

	//Creating trees manually for simplicity
	Node* tree1 = new Node(100);
	tree1->left = new Node(50);
	tree1->right = new Node(300);
	tree1->left->left = new Node(20);
	tree1->left->right = new Node(70);

	Node* tree2 = new Node(80);
	tree2->left = new Node(40);
	tree2->right = new Node(120);

	Node* newHead = mergeTree(tree1, tree2);
	cout << "\n\n" << newHead->data << endl;

}

//Node** mergeTree(Node* tree1, Node* tree2) {
//	cout << tree1->data << endl;
//	cout << tree2->data << endl;
//
//	return &tree1;
//}
Node* mergeTree(Node* tree1, Node* tree2) {

	cout << tree1->data << endl;
	cout << tree2->data << endl;

	//Traverse both trees inOrder and store results in vector
	vector<Node*> vecTree1;
	toVector(tree1, vecTree1);
	vector<Node*> vecTree2;
	toVector(tree2, vecTree2);


	return tree1; //returning value of pointer, or pointer's address (dangling)?
}

void toVector(Node* head, vector<Node*> myVec) {
	if (head->left != NULL) {

	}

	//store

	if (head->right != NULL) {

	}
}
