#include <iostream>
#include <vector>

using namespace std;

int main() {

	/*
	 * Sample Input:
	 *   5 5			//Room dimensions (x,y)
	 *   1 2			//Roomba initial position
	 *   1 0			//Dirt patch, one per line
	 *   2 2
	 * 	 2 3
	 * 	 NNESEESWNWW		//Driving directions
	 *
	 */

	/*
	 * Hard-code inputs to start
	 */
	int roomX = 5, roomY = 5, rmbaInitX = 1, rmbaInitY = 2;
	//cin >> roomX >> roomY >> rmbaInitX >> rmbaInitY;

	cout << roomX << ", " << roomY << ", " << rmbaInitX << ", " << rmbaInitY << endl;

	int dirt[3][2] = {
			{1, 0},
			{2, 2},
			{2, 3}
	};

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 2; j++) {
			cout << dirt[i][j] << " ";
		} cout << endl;
	}

	//Algorithm

}

