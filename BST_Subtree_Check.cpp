#include <iostream>
#include <vector>

using namespace std;

bool isSubtree(struct Node*, Node*);
void parseToVector(Node*, vector<Node*>&);
bool compareVector(vector<Node*>, vector<Node*>);

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

	/* Check if one BST is a subtree of another BST

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
	   1. There might be a more efficient algorithm, but I'll start with this one.
	   2. Algorithm checks for subtree, not subset

	   Current Algorithm Time Complexity:
	       O(mn), where m and n is the number of nodes in Tree 1 and Tree 2.

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
		cout << "\n\nTree 2 is a subtree!\n";
	} else {
		cout << "\n\nTree 2 is NOT a subtree!\n";
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

	//compareVector returns tree is subtree (in vecTree2) is found in vecTree1
	return compareVector(vecTree1, vecTree2);

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

bool compareVector(vector<Node*> tree1, vector<Node*> tree2) {

	bool match;

	for (int i = 0; i < tree1.size(); i++) {
		//If current match tree2's head
		if (tree1[i]->data == tree2[0]->data) {
			match = false;
			//Check for every subsequent element in tree2
			for (int j = 0; j < tree2.size(); j++) {
				//If not out of bound and matches
				if (i + j < tree1.size() && tree1[i+j]->data == tree2[j]->data) {
					match = true;
				} else {
					match = false;
				}
			}
		}
	}

	return match;

}
