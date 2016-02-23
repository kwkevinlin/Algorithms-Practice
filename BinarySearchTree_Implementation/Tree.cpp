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
	//Assuming no duplicates possible
	if (data < itr->data) {
		if (itr->left == NULL){
			cout << "Inserting " << data << endl;
			itr->left = new Node(data);
		} else {
			cout << "Left\n";
			insert(itr->left, data);
		}
	}
	else if (data > itr->data) {
		if (itr->right == NULL){
			cout << "Inserting " << data << endl;
			itr->right = new Node(data);
		} else {
			cout << "Right\n";
			insert(itr->right, data);
		}
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
