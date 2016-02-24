#include <iostream>
#include "Tree.h"

using namespace std;

int main() {

	/*
	 * Binary Tree Implementation
	 *
	 *	In progress
	 *
	 */

	Tree bst(5);
	cout << "Root " << bst.root->data << endl;
	bst.insert(3);
	bst.insert(8);
	bst.insert(1);
	bst.insert(2);
	bst.insert(9);
	bst.insert(4);

	cout << "\nDFS Print\n";
	bst.DFS();
	cout << "\nBFS Print\n";
	bst.BFS();
	cout << "\nPreOrder Print\n";
	bst.preOrder();

}
