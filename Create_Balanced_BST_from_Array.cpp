#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node() {
		data = -1;
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
	 * Given an array with unique integer elements, write an
	 * algorithm to create a binary search tree with minimal
	 * height.
	 *
	 * Adapted from Cracking the Coding Interview
	 * Chapter 4, Question 3
	 *
	 */

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

}
