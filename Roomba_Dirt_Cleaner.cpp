#include <iostream>
#include <vector>
#include <map>
#include <sstream>

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
	 * Input variables
	 */
	int roomX = 5, roomY = 5, roombaX = 1, roombaY = 2;
	string instructions;
	map<vector<int>, int> dirtMap; //Dirt coordinates stored in map for fast lookup

	cin >> roomX >> roomY >> roombaX >> roombaY;

	vector<int> tmp;


	int breakOut = 0;
	string line;
	while (getline(cin, line)) {
		istringstream is(line);
		string word;
		while (is >> word) {
			int val = atoi(word.c_str());
			if (val || word == "0") { //Input is integer
				tmp.push_back(val);
				if (tmp.size() == 2) { //Store pair into map
					dirtMap[tmp]++;
					tmp.clear();
				}
			} else { //Input is instruction
				instructions = word;
				breakOut = 1;
				break;
			}
		}
		if (breakOut == 1) {
			break;
		}
	}


	/* Algorithm
	 */
	int cleaned = 0;
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
		if (dirtMap.count(pos) > 0) {
			dirtMap.erase(pos); //Erase from known dirt coordinates
			cleaned++;
		}
	}

	cout << endl;

	//Results printout
	cout << roombaX << " " << roombaY << endl; //Final position
	cout << cleaned << endl;

}

