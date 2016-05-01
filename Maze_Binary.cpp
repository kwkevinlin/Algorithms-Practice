#include <iostream>
#include <vector>

using namespace std;

const int width = 3;
const int height = 3;
bool verifyMaze(int[][width]);

int main() {

	/*
	 * If you have a 2D array of 1's and 0's, find a way to leave the maze
	 * from top to bottom only following the path of 1's. If there is a way,
	 * return true or false.
	 *	EX: 0 1 0
	 *		0 1 1
	 *		0 0 1
	 *
	 *	Approach:
	 *	    Whenever there is a 1, check below if there is a 1 or not. If not,
	 *	    check if right is a 1. If both not, check if at end of path. If yes,
	 *	    return true. Else, return false.
	 */

	int maze[height][width] = {
			{0, 1, 0},
			{0, 1, 1},
			{0, 0, 1}
	};

	if (verifyMaze(maze)) {
		cout << "Success! Maze can be traversed.\n";
	} else {
		cout << "Maze cannot be traversed!\n";
	}

}

bool verifyMaze(int maze[][width]) {

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			//If find 1
			if (maze[i][j] == 1) {
				//Check if below is 1 too
				if (i + 1 < height && maze[i+1][j] == 1) {
					//Below is 1
				} else {
					//If right is not 1, then below has to be 1, or else maze can't continue
					if (j + 1 < width && maze[i][j+1] == 1) {
						//Right is 1
					} else if (i == height - 1) {
						//End of maze
						return true;
					} else {
						//Cannot find 1 to the right or bottom of current 1
						return false;
					}
				}
			}
		}
	}
}
