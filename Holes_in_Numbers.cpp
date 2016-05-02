#include <iostream>

using namespace std;

int solvePuzzle(int);

int main() {

	/*
	 * Given a number, find the total number of holes
	 * in the digits.
	 *
	 * For example:
	 *     0 Hole: 1, 2, 3, 5, 7
	 *     1 Hole: 0, 4, 6, 9
	 *     2 Holes: 8
	 *
	 *     Sample:
	 *     24 -> 1
	 *     1264 -> 2
	 *     9899 -> 5
	 *     349 -> 2
	 *
	 */

	cout << "Holes: " << solvePuzzle(1264) << endl;

}

int solvePuzzle(int num) {

	string myNum = to_string(num);

	int holes = 0;
	for (int i = 0; i < myNum.length(); i++) {
		if (myNum[i] == '0' || myNum[i] == '4' || myNum[i] == '6' || myNum[i] == '9') {
			holes = holes + 1;
		} else if (myNum[i] == '8') {
			holes = holes + 2;
		}
	}

	return holes;
}