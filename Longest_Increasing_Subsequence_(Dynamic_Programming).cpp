#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

	/*
	 * Find the Longest Increasing Subsequence using
	 * dynamic programming.
	 *
	 * For example:
	 *     5 2 8 6 3 6 9 7
	 *       >     > > >
	 *
	 * Longest sequence: 4
	 *     From 2 -> 3 -> 6 -> 9
	 *
	 * Method 1:
	 *     Create adjacency list of smaller elements,
	 *     then use standard DP to solve
	 */

	int arr[] = {5, 2, 8, 6, 3, 6, 9, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int max[size];

	max[0] = 1;

	//Create adjacency list, where edge = all elements smaller
	int arrSorted[size];
	copy(arr, arr + size, arrSorted);

	//Sort array to get all smaller elements easier
	sort(arrSorted, arrSorted + size);

	for (int i = 1; i < sizeof(arr)/sizeof(arr[0]); i++) {

	}
}
