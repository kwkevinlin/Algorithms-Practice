#include <iostream>
#include <cstdlib>

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
	Node(int n) {
		data = n;
		left = NULL;
		right = NULL;
	}
};

int main() {

	/* Creating trees manually for simplicity

		     Tree 1           Tree 2
			  100				80
	          /  \			   /  \
	        50    300        40   120
	       / \
	      20  70
	*/

	Node* tree1(100);
	tree1->left = new Node(50);
	tree1->right = new Node(300);
	tree1->left->left = new Node(20);
	tree1->left->right = new Node(70);

	Node* tree2(80);
	tree2->left = new Node(40);
	tree2->right = new Node(120);
	
	

}
