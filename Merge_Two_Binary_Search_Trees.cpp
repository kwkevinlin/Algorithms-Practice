#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Node* mergeTree(Node*, Node*);
void toVector(Node*, vector<Node*>&);
void mergeVec(int, int, vector<Node*>, vector<Node*>, vector<Node*>&);
Node* buildBalancedBST(vector<Node*>, int, int);
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

	/* Merging two Binary Search Trees (BST)

	           Tree 1           Tree 2
	            100               80
	           /   \             /  \
	         50    300         40   120
	        /  \
	      20    70
	      
	    Approach:
	    Read each tree in inOrder into vectors to get the sorted sequence. Assuming no duplicates, merge 
	    the two vectors together, then rebuild the tree using a balanced BST algorithm.
	    
	    Complexity:
	    O(n+m)
	    
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

	//newHead = head of merged tree
	Node* newHead = mergeTree(tree1, tree2);

	//Preorder print tree to confirm results
	cout << "\n\nMerged Tree in Pre-Order:\n";
	printTree(newHead);


	/* Result of merged tree (balanced)
	 *
	 *        New Tree
	 *           70
	 *          /  \
	 *       40     100
	 *      /  \   /   \
	 *    20   50 80   120
	 *                   \
	 *                   300
	 */

}

Node* mergeTree(Node* tree1, Node* tree2) {

	//Traverse both trees inOrder then store them both into vectors
	vector<Node*> vecTree1;
	vector<Node*> vecTree2;
	toVector(tree1, vecTree1);
	toVector(tree2, vecTree2);

	//Printout vectors
	cout << "vecTree1:\n";
	for (int i = 0; i < vecTree1.size(); i++) {
		cout << vecTree1[i]->data << " ";
	}
	cout << "\nvecTree2:\n";
	for (int i = 0; i < vecTree2.size(); i++) {
		cout << vecTree2[i]->data << " ";
	}

	//Merge the two (sorted) vectors
	int minLength, maxLength;
	vector<Node*> vecMerged;

	if (vecTree1.size() > vecTree2.size()) {
		minLength = vecTree2.size();
		maxLength = vecTree1.size();
		mergeVec(minLength, maxLength, vecTree2, vecTree1, vecMerged);
	} else {
		minLength = vecTree1.size();
		maxLength = vecTree2.size();
		mergeVec(minLength, maxLength, vecTree2, vecTree1, vecMerged);
	}

	cout << "\n\nvecMerged:\n";
	for (int i = 0; i < vecMerged.size(); i++) {
		cout << vecMerged[i]->data << " ";
	}

	/*
	 * Return the head of the newly built balanced BST
	 * */
	return buildBalancedBST(vecMerged, 0, vecMerged.size() - 1);
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

void mergeVec(int smallLength, int bigLength, vector<Node*> smallTree, vector<Node*> bigTree, vector<Node*> &vecMerged) {

	int i = 0; //smallTree counter
	int	j = 0; //bigTree counter

	//Compare and merge until one is finished pushing (no more elements)
	while (i < smallLength && j < bigLength) {
		if (smallTree[i]->data < bigTree[j]->data) {
			vecMerged.push_back(smallTree[i]);
			i++;
		}
		else if (smallTree[i]->data > bigTree[j]->data) {
			vecMerged.push_back(bigTree[j]);
			j++;
		}
	}

	//Fill in rest
	if (i < smallLength) {
		for (int x = i; x < smallLength; x++) {
			vecMerged.push_back(smallTree[x]);
		}
	}
	else if (j < bigLength) {
		for (int x = j; x < bigLength; x++) {
			vecMerged.push_back(bigTree[x]);
		}
	}

}

Node* buildBalancedBST(vector<Node*> vecMerged, int start, int end) {

	//Base case, then child == NULL
	if (start > end)
		return NULL;

	int mid = (start + end)/2;

	Node* newNode = vecMerged[mid];

	newNode->left = buildBalancedBST(vecMerged, start, mid - 1);
	newNode->right = buildBalancedBST(vecMerged, mid + 1, end);

	return newNode;
}

void printTree(Node* head) {

	//Pre-Order print to retain structure
	cout << head->data << " ";

	if (head->left != NULL) {
		printTree(head->left);
	}

	if (head->right != NULL) {
		printTree(head->right);
	}

}
