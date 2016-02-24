/*
 * Tree.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Kevin Lin
 *
 *  Project In Progress
 */

#include <cstddef>
#include <iostream>
#include <queue>
#include "Tree.h"

using namespace std;

Tree::Tree() {
	root = new Node();
}

Tree::Tree(int n) {
	root = new Node(n);
}

Tree::~Tree() {
}

Tree::Node::Node() {
	data = -1;
	left = NULL;
	right = NULL;
}

Tree::Node::Node(int n) {
	data = n;
	left = NULL;
	right = NULL;
}

void Tree::insert(int data) {
	if (root == NULL) {
		root = new Node(data);
	} else {
		Node* itr = root;
		insert(itr, data); //Calls function below for recursion
	}
}

void Tree::insert(Node* itr, int data) {
	//Assuming no duplicates allowed
	if (data < itr->data) {
		if (itr->left == NULL){
			cout << "Inserting " << data << endl;
			itr->left = new Node(data);
		} else {
			insert(itr->left, data);
		}
	}
	else if (data > itr->data) {
		if (itr->right == NULL){
			cout << "Inserting " << data << endl;
			itr->right = new Node(data);
		} else {
			insert(itr->right, data);
		}
	}
	else if (data == itr->data) {
		cout << "Duplicate detected: " << data << "\n";
		return;
	}
}

void Tree::deleteNode() {

}

void Tree::DFS() {
	Node* itr = root;
	DFS(itr);
}

void Tree::DFS(Node* itr) {

	cout << itr->data << " ";

	if (itr->left != NULL) {
		DFS(itr->left);
	}
	if (itr->right != NULL) {
		DFS(itr->right);
	}
}

void Tree::BFS() {
	Node* itr = root;
	queue<Node*> bfsQueue;
	bfsQueue.push(itr);

	//While elements in queue
	while (bfsQueue.size() > 0) {

		itr = bfsQueue.front();

		cout << itr->data << " ";

		if (itr->left != NULL) {
			bfsQueue.push(itr->left);
		}
		if (itr->right != NULL) {
			bfsQueue.push(itr->right);
		}

		bfsQueue.pop();
	}

}

void Tree::inOrder() {
	Node* itr = root;
	inOrder(itr);
}

void Tree::inOrder(Node* itr) {
	//Left first, print mid, then right
	if (itr->left != NULL) {
		inOrder(itr->left);
	}

	cout << itr->data << " ";

	if (itr->right != NULL) {
		inOrder(itr->right);
	}
}

void Tree::preOrder() {
	Node* itr = root;
	preOrder(itr);
}

void Tree::preOrder(Node* itr) {
	//Print, then left, then right. Like DFS
	cout << itr->data << " ";

	if (itr->left != NULL) {
		preOrder(itr->left);
	}
	if (itr->right != NULL) {
		preOrder(itr->right);
	}
}

void Tree::postOrder() {
	Node* itr = root;
	postOrder(itr);
}

void Tree::postOrder(Node* itr) {
	//Child first, then node
	if (itr->left != NULL) {
		postOrder(itr->left);
	}
	if (itr->right != NULL) {
		postOrder(itr->right);
	}

	cout << itr->data << " ";
}
