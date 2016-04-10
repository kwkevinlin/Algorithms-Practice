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
	 * Note:
	 *     Known issue. If input:
	 *     1
	 *     4
	 *     5
	 *     2 0 1 4 3
	 *
	 *     Output:
	 *     1 0
	 *
	 *     Reason: 4 - 2 = 2. Since 2 (result) is in array,
	 *     but is itself, it counts as found. So to fix,
	 *     have a check to make sure 2 (result) does NOT
	 *     equal to 2 (operand).
	 *     4 - 2 = 2
	 *     sum - cost[j] = tmp
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

				//If same, print [0] and [1]
				if (cost[j] == tmp) {
					cout << hash[cost[j]][0] << " " << hash[tmp][1] << endl; //where hash[cost[j]] == hash[tmp]
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
