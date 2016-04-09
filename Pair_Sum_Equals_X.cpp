#include <iostream>

using namespace std;

struct Node;
Node* buildTree(int[], int, int);
void printTree(Node*);

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
	 * Given a list, find a pair such as the sum
	 * is X, where X is given.
	 *
	 * Adapted from HackerRank:
	 * Ice Cream Parlor
	 * https://www.hackerrank.com/challenges/icecream-parlor
	 *
	 */

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int cases, flavors, n, sum;

	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> flavors;

		//Read flavors cost into cost[]
		int cost[flavors];
		for (int j = 0; j < flavors; j++) {
			cin >> n;
			cost[j] = n;
		}



	}
	return 0;


}
