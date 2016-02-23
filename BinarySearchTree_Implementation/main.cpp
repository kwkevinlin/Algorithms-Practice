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
	cout << "Start " << bst.root->data << endl;
	bst.insert(3);
	bst.insert(8);

	cout << "\nDFS Print\n";
	bst.DFS();

}
