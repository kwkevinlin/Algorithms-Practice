/*
 * Tree.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kevin Lin
 *
 *  Project In Progress
 */

#ifndef TREE_H_
#define TREE_H_

class Tree {
public:
	Tree();
	Tree(int);
	~Tree();

	void insert();
	void deleteNode();

	struct Node {
		Node();
		Node(int);

		int data;
		Node* left;
		Node* right;
	};

	Node* start;

private:
	/*
	 * The following will be in private, but is currently in
	 * public for testing
	 *
	 * 		Node* start
	 * 		struct Node {}
	 */

};

#endif /* TREE_H_ */
