#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node* mergeTree(Node*, Node*);
void toVector(Node*, vector<Node*>&);
void mergeVec(int, int, Node*, Node*, unordered_set<Node*>);

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

	/*
	 *
	 *  RE-DO THIS PROBLEM
	 *		Do recursive way instead, way better complexity
	 *
	 */

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

	//Testing toVector
	for (int i = 0; i < vecTree1.size(); i++) {
		cout << vecTree1[i]->data << " ";
	}

	vector<Node*> vecTree2;
	toVector(tree2, vecTree2);

	//Combine two vectors and remove duplicate
	int minLength, maxLength;
	unordered_set<Node*> setMerged;

	//Throw following into mergeVec();
	if (vecTree1.size() > vecTree2.size()) {
		minLength = vecTree2.size();
		maxLength = vecTree1.size();
		mergeVec(minLength, maxLength, tree2, tree1, setMerged);
	} else {
		minLength = vecTree1.size();
		maxLength = vecTree2.size();
	}

	//Test set
	/*
	 * Issues: Set inserts to front it seems, so order wrong
	 *     BST insertion will be extremely unbalanced
	 */
	cout << endl;
	for (auto kv : setMerged) {
		cout << kv->data << " ";
	}

	//Create balanced BST


	return tree1; //returning what it is pointing to
}

void toVector(Node* head, vector<Node*> &myVec) {

	//Storing via inOrder
	if (head->left != NULL) {
		toVector(head->left, myVec);
	}

	//Passed by reference, so it modifies vector directly
	myVec.push_back(head); //Storing in data of head

	if (head->right != NULL) {
		toVector(head->right, myVec);
	}
}

void mergeVec(int smallLength, int bigLength, Node* smallTree, Node* bigTree, unordered_set<Node*> &setMerged) {
	//Throw merging into here later
}
