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
#include "Tree.h"

using namespace std;

Tree::Tree() {
	start = new Node();
}

Tree::Tree(int n) {
	start = new Node(n);
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
	Node* itr = start;
	insert(itr, data); //Calls function below for recursion
}

void Tree::insert(Node* itr, int data) {
	//Assuming no duplicates for now
	if (itr == NULL) {
		itr = new Node(data);
		cout << "Inserting " << data << endl;
	}
	else if (data < itr->data) {
		cout << "Left\n";
		insert(itr->left, data);
	}
	else if (data > itr->data) {
		cout << "Right\n";
		insert(itr->right, data);
	}
}

void Tree::deleteNode() {

}
