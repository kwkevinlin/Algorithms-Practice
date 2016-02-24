#include <iostream>
#include "Tree.h"

using namespace std;

int main() {

	/*
	 * Binary Tree Implementation
	 *
	 * Test Tree looks like:
	 *
	 *         _6_
	 *       /     \
	 * 	    2	    7
	 * 	   / \       \
	 * 	  1   4	      9
	 * 	     / \     /
	 *      3   5   8
	 *
	 */

	Tree bst(6);
	cout << "Root " << bst.root->data << endl;
	bst.insert(2);
	bst.insert(7);
	bst.insert(1);
	bst.insert(4);
	bst.insert(3);
	bst.insert(5);
	bst.insert(9);
	bst.insert(8);


	cout << "\nDFS Print\n";
	bst.DFS();
	cout << "\nBFS Print\n";
	bst.BFS();
	cout << "\nInOrder Print\n";
	bst.inOrder();
	cout << "\nPreOrder Print\n";
	bst.preOrder();
	cout << "\nPostOrder Print\n";
	bst.postOrder();

}
