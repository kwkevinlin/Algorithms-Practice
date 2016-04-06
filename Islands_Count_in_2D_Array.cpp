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
	 */

	int land[numHeight][numWidth] = {
			{1, 1, 0, 1},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 1}
	};


	int islands = countIslands(land);
	cout << "Number of islands in 2D array:\n" << islands << endl;

}

int countIslands(int land[][numWidth]) {
	int islands;

	for (int i = 0; i < numHeight; i++) {
		for (int j = 0; j < numWidth; j++) {

			if (land[i][j] == 1) {
				discover(land, i, j);
				islands++;
			}

		}
	}

}

void discover(int land[][numWidth], int i, int j) {
	//Check all four directions. Visited, mark as -1
}
