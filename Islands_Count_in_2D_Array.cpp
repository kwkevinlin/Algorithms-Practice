#include <iostream>

using namespace std;

const int numWidth = 4;
const int numHeight = 4;
void discover(int[][numWidth], int, int);
int countIslands(int[][numWidth]);

int main() {

	/*
	 * Given a 2D array of 1s and 0s, identify
	 * the number of distinct islands in the array.
	 *     Island = 1s
	 *
	 *     For example:
	 *     {{1, 1, 0, 1},
	 *      {0, 1, 0, 0},
	 *      {0, 0, 0, 0},
	 *      {0, 0, 0, 1}}
	 *
	 *     Number of islands will be 3
	 *
	 * Solution:
	 *     2D loop through the array. For each 1 found,
	 *     call discover() on that index. In discover,
	 *     modify value of 1 to -1 so that [i][j] wont,
	 *     be visited again. Then, still in discover,
	 *     check all 4 directions (up, down, left, right)
	 *     to check if there are any connecting lands.
	 *     If there are, call discover on the index (i,j)
	 *     of that land.
	 */

	int land[numHeight][numWidth] = {
			{1, 1, 0, 1},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 1}
	};


	int islands = countIslands(land);
	cout << "Number of islands:\n" << islands << endl;

}

int countIslands(int land[][numWidth]) {
	int islands = 0;

	for (int i = 0; i < numHeight; i++) {
		for (int j = 0; j < numWidth; j++) {

			if (land[i][j] == 1) {
				discover(land, i, j);
				islands++;
			}

		}
	}

	return islands;

}

void discover(int land[][numWidth], int i, int j) {
	//Check all four directions. Visited, mark as -1

	//Left
	if (j - 1 >= 0 && land[i][j-1] == 1) {
		land[i][j-1] = -1;
		discover(land, i, j-1);
	}
	//Right
	if (j + 1 < numWidth && land[i][j+1] == 1) {
		land[i][j+1] = -1;
		discover(land, i, j+1);
	}
	//Up
	if (i - 1 >= 0 && land[i-1][j] == 1) {
		land[i-1][j] = -1;
		discover(land, i-1, j);
	}
	//Down
	if (i + 1 < numHeight && land[i+1][j] == 1) {
		land[i+1][j] = -1;
		discover(land, i+1, j);
	}
}
