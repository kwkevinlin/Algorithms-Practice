/*
 * Tree.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kevin Lin
 */

#ifndef TREE_H_
#define TREE_H_

struct Node {
	int data;
	Node* left;
	Node* right;
};

class Tree {
public:
	Tree();
	~Tree();

private:

};

#endif /* TREE_H_ */
