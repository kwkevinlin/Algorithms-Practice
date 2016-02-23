/*
 * Tree.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Kevin Lin
 *
 *  Project In Progress
 */

#include <cstddef>
#include "Tree.h"

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

void Tree::insert() {

}

void Tree::deleteNode() {

}
