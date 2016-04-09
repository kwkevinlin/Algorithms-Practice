#include <iostream>
#include <unordered_set>

using namespace std;

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
		cin >> sum >> flavors;

		//Read flavors cost into cost[]
		int cost[flavors];
		unordered_set<int> hash;
		for (int j = 0; j < flavors; j++) {
			cin >> n;
			cost[j] = n;
			hash.insert(n);
		}

		int tmp;
		for (int j = 0; j < flavors; j++) {
			tmp = sum - cost[j];
			if (hash.count(tmp) > 0) {
				if (cost[j] > tmp) {
					cout << tmp << " " << cost[j] << endl;
				} else {
					cout << cost[j] << " " << tmp << endl;
				}
				break;
			}
		}


	}
	return 0;

}
