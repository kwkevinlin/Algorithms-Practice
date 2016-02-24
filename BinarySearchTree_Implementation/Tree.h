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

#include <queue>

class Tree {
public:
	Tree();
	Tree(int);
	~Tree();

	void insert(int);
	void deleteNode();

	void DFS();
	void BFS();

	void inOrder();
	void preOrder();
	void postOrder();

	struct Node {
		Node();
		Node(int);

		int data;
		Node* left;
		Node* right;
	};

	Node* root;

private:
	/*
	 * The following will be in private, but is currently in
	 * public for easier testing
	 *
	 * 		Node* start
	 * 		struct Node {}
	 */

	void insert(Node*, int);
	void deleteNode(Node*, int);

	void DFS(Node*);

	void inOrder(Node*);
	void preOrder(Node*);
	void postOrder(Node*);

};

#endif /* TREE_H_ */
