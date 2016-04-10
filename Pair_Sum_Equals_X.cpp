#include <iostream>
#include <vector>
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
		unordered_map<int, vector<int>> hash;
		for (int j = 0; j < flavors; j++) {
			cin >> n;
			cost[j] = n;
			hash[n].push_back(j + 1); //Since first element should output 1 not 0
		}

		//For every index, take sum - cost[index] and see if result is in the cost array
		int tmp;
		for (int j = 0; j < flavors; j++) {
			tmp = sum - cost[j];
			if (hash.count(tmp) > 0) { //If such element exists

				//If there's a repeat of that price
				if (hash[tmp].size() > 1) { //Print [0] then [1]
					fflush(stdout);
					cout << hash[cost[j]][0] << " " << hash[tmp][1]; //where hash[cost[j]] == hash[tmp]
				}
				else { //Always print [0]

					fflush(stdout);
					if (hash[cost[j]][0] > hash[tmp][0]) {
						cout << hash[tmp][0] << " " << hash[cost[j]][0] << endl;
					} else {
						cout << hash[cost[j]][0] << " " << hash[tmp][0] << endl;
					}
				}
				break;
			}
		}


	}
	return 0;

}
