#include <iostream>
#include <vector>

using namespace std;

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
	 *	    Whenever I see a 1, check below if there is a 1. If not, check if right is a 1.
	 *	    If both not, check if at end of path. If yes, return true. Else, false.
	 */

	int maze[3][3] = {
			{0, 1, 0},
			{0, 1, 1},
			{0, 0, 1}
	};




}
