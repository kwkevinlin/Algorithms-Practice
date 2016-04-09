#include <iostream>
#include <unordered_map>

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

	int cases, flavors, n, sum;

	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> sum >> flavors;

		//Read flavors cost into cost[]
		int cost[flavors];
		unordered_map<int, int> hash;
		for (int j = 0; j < flavors; j++) {
			cin >> n;
			cost[j] = n;
			hash[n] = j;
		}

		int tmp;
		for (int j = 0; j < flavors; j++) {
			tmp = sum - cost[j];
			if (hash.count(tmp) > 0) {
				if (cost[j] > tmp) {
					cout << hash[tmp] + 1 << " " << hash[j] + 1 << endl;
				} else {
					cout << hash[j] + 1 << " " << hash[tmp] + 1 << endl;
				}
				break;
			}
		}


	}
	return 0;

}
