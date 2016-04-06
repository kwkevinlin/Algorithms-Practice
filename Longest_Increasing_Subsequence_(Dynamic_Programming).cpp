#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

	/*
	 * Find the Longest Increasing Subsequence using
	 * dynamic programming.
	 *     Then print out path.
	 *
	 * For example:
	 *     5 2 8 6 3 6 9 7
	 *       >     > > >
	 *       >     > >   >
	 *
	 * Longest sequence: 4
	 *     From 2 -> 3 -> 6 -> 9   (or)
	 *     From 2 -> 3 -> 6 -> 7
	 *
	 */

	int arr[] = {5, 2, 8, 6, 3, 6, 9, 7};

	int maxArr[sizeof(arr)/sizeof(arr[0])];
	int max = -1;

	//DP from start to end, O(n^2) solution
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		//DP base case
		maxArr[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				maxArr[i] = maxArr[j] + 1;
				cout << i << " " << j << ", " << maxArr[i] << endl;

				if (maxArr[i] > max) {
					max = maxArr[i];
				}
			}
		}
	}

	cout << max << endl;
}
