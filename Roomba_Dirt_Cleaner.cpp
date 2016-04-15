#include <iostream>
#include <array>
#include <vector>
#include <map>

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
	int roomX = 5, roomY = 5, roombaX = 1, roombaY = 2;
	//cin >> roomX >> roomY >> roombaX >> roombaY;

	cout << roomX << ", " << roomY << ", " << roombaX << ", " << roombaY << endl;

	//std::array for map hash
	vector<vector<int>> dirt = {{
			{{1, 0}},
			{{2, 2}},
			{{2, 3}}
	}};

	map<vector<int>, int> map;
	for (int i = 0; i < 3; i ++) {
		map[dirt[i]]++; //Add to map
		for (int j = 0; j < 2; j++) {
			cout << dirt[i][j] << " ";
		} cout << endl;
	}

	string instructions = "NNESEESWNWW";

	/* Algorithm
	 *
	 * Note: Algorithm does not currently check if roomba is out of bounds.
	 *
	 */
	for (int i = 0; i < instructions.length(); i++) {

		if (instructions[i] == 'N') {
			roombaY++;
		} else if (instructions[i] == 'E') {
			roombaX++;
		} else if (instructions[i] == 'S') {
			roombaY--;
		} else if (instructions[i] == 'W') {
			roombaX--;
		}

		vector<int> pos;
		pos.push_back(roombaX);
		pos.push_back(roombaY);
		if (map.count(pos) > 0) {
			cout << "Dirt! " << pos[0] << ", " << pos[1] << endl;
			map.erase(pos);
		}
	}

	cout << "Final position: " << roombaX << ", " << roombaY << endl;

}

