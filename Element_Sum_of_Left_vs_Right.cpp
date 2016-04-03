#include <iostream>

using namespace std;

int main() {

	/*
	 * Determine if there is an element in the array such that the
	 * sum of the elements on the left == sum of the elements on
	 * the right.
	 *
	 * Example:
	 *     Input: 2        //Number of test cases
	 *            3        //Length of following case
	 *            1 2 3    //Test case
	 *            4
	 *            1 2 3 3
	 *     Output: NO
	 *             YES
	 *     Explanation:
	 *             Case 1: No such element
	 *             Case 2: [2], because (left) 1 + 2 == (right) 3
	 *
	 *
	 * Question adapted from:
	 *     HackerRank - Sherlock and Array
	 *     https://www.hackerrank.com/challenges/sherlock-and-array
	 *
	 * Solution: O(n)
	 *     Dynamically fill sumL[length] array for sum of all element
	 *     to the left of index [i]; repeat for sumR from the other
	 *     direction as well.
	 *
	 *     For example, with given inputs above:
	 *     SumL = [1, 3, 6, 9]; //Because [(1), (1+2=3), (3+3=6), (6+3=9)]
	 *     SumR = [3, 6, 8, 9];
	 *
	 *     Then, loop through the original input [1, 2, 3, 3] from [1] to
	 *     second to last (the first and last are unnecessary), check if
	 *     any index satisfies sumL[i-1] == sumR[i+1]. If equal, return
	 *     true. Else, return false.
	 *
	 *     Example: Index [2] = 3
	 *     SumL[i-1] == 3 == sumR[i+1] == 3
	 */

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int testCases, length, flag;

	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		cin >> length;

		//Temporary storing every element into array
		int storage[length];
		for (int j = 0; j < length; j++) {
			cin >> storage[j];
		}

		//If single element, cout YES
		if (length == 1) {
			cout << "YES\n";
			continue;
		}

		flag = 0;

		//Storing all sums dynamically to array
		int sumL[length], sumR[length];
		sumL[0] = storage[0];
		sumR[length-1] = storage[length-1];
		for (int k = 1; k < length; k++) {
			sumL[k] = sumL[k-1] + storage[k];
		}
		for (int k = length - 2; k >= 0; k--) {
			sumR[k] = sumR[k+1] + storage[k];
		}

		//If any elements match
		for (int k = 1; k < length - 1; k++) {
			if (sumL[k-1] == sumR[k+1]) {
				flag = 1;
				break;
			}
		}

		//Check flags
		if (flag == 1) {
			cout << "YES\n";
			flag = 0;
		} else {
			cout << "NO\n";
		}
	}

	return 0;

}
