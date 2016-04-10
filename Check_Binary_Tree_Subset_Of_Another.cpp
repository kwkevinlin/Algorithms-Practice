#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node() {
		data = 1;
		left = NULL;
		right = NULL;
	}

	Node(int n) {
		data = n;
		left = NULL;
		right = NULL;
	}
};

int main() {

	/*
	 * Given two trees, check if one tree is contained
	 * in the other tree. (Check if one tree is a subset
	 * of the other).
	 *
	 */

}
