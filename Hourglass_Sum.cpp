#include <iostream>

using namespace std;

int main() {

	/*
	 * You are given a 2D array with dimensions 6*6. An hourglass
	 * in an array is defined as a portion shaped like this:
	 *
	 *    a b c
	 *      d
	 *    e f g
	 *
	 * For example, if we create an hourglass using the number 1
	 * within an array full of zeros, it may look like this:
	 *
	 *    1 1 1 0 0 0
	 *    0 1 0 0 0 0
	 *    1 1 1 0 0 0
	 *    0 0 2 4 4 0
	 *    0 0 0 2 0 0
	 *    0 0 1 2 4 0
	 *
	 * Note that there are many hourglasses in the array, for ex:
	 *
	 *    1 1 1     1 1 0     1 0 0     2 4 4
	 * 	    1         0         0         2
	 *	  1 1 1     1 1 0     1 0 0     1 2 4
	 *
	 * For which the first three are formed in the first row.
	 * Integers in the array can range from -9 to 9.
	 *
	 * Output:
	 *     Print the largest sum among all the hourglasses in the
	 *     array.
	 *
	 *     With given input above, output will be:
	 *         19
	 *
	 *
	 * Adapted from HackerRank:
	 * 2D Array - DS
	 * https://www.hackerrank.com/challenges/2d-array
	 *
	 */

	int arr[6][6] = {
			{1, 1, 1, 0, 0, 0},
			{0, 1, 0, 0, 0, 0},
			{1, 1, 1, 0, 0, 0},
			{0, 0, 2, 4, 4, 0},
			{0, 0, 0, 2, 0, 0},
			{0, 0, 1, 2, 4, 0}
	};

	int sum, max = (7 * -9); //Most min possible for each hourglass
	int maxArr[7];

	//numWidth, numHeight hard-coded to 6 currently
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {

			sum = 0;
			if (j + 2 < 6 && i + 2 < 6) { //Not out of bounds
				sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

				if (sum > max) {
					max = sum;

					//Storing to maxArr
					maxArr[0] = arr[i][j];
					maxArr[1] = arr[i][j+1];
					maxArr[2] = arr[i][j+2];
					maxArr[3] = arr[i+1][j+1];
					maxArr[4] = arr[i+2][j];
					maxArr[5] = arr[i+2][j+1];
					maxArr[6] = arr[i+2][j+2];
				}
			}
		}
	}

	cout << "Max: " << max << endl;
	cout << "Hourglass:\n";
	cout << "   " << maxArr[0] << " " << maxArr[1] << " " << maxArr[2] << endl <<
			"     " << maxArr[3] << endl <<
			"   " << maxArr[4] << " " << maxArr[5] << " " << maxArr[6] << endl;

}

