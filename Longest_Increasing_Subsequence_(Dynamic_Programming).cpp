#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;

int longestIncSubseq(int[], int);

int main() {

	/*
	 * Find the Longest Increasing Subsequence using
	 * dynamic programming.
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

	//Standard test case
	int arr[] = {5, 2, 8, 6, 3, 6, 9, 7};

	//Random test case
	//	int arr[8];
	//	srand(time(NULL));
	//	cout << "Sequence:\n";
	//	for (int i = 0; i < 8; i++) {
	//		arr[i] = rand() % 10;
	//		cout << arr[i] << " ";
	//	}

	cout << "\nLongest Increasing Subsequence:\n" << longestIncSubseq(arr, sizeof(arr)/sizeof(arr[0])) << endl;

}

int longestIncSubseq(int arr[], int size) {

	//maxArr stores max dists so far
	int maxArr[size];
	int max = -1, currMax;

	//DP from start to end, O(n^2) solution
	for (int i = 0; i < size; i++) {
		//DP base case
		maxArr[i] = 1;
		currMax = -1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				//maxArr[i] = maxArr[j] + 1;

				//				if (maxArr[i] > max) {
				//					max = maxArr[i];
				//				}

				//Get longest increasing subsequence
				if (maxArr[j] > currMax) {
					currMax = maxArr[j];
				}
			}
			maxArr[i] = currMax + 1;
			if (maxArr[i] > max) {
				max = maxArr[i];
				//cout << arr[i] << " at " << maxArr[i] << endl;
			}
		}
	}

	//Debug
	for (int i = 0; i < size; i++) {
		cout << maxArr[i] << " ";
	}

	return max;

}
