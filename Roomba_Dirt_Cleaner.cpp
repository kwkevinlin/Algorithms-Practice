#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void parseInputs(int&, int&, int&, int&, string&, map<vector<int>, int>&);
void cleanRoom(string, int&, int&, int&, int, int, map<vector<int>, int>&);

int main() {

	/*
	 * Sample Input:
	 *   5 5			//Room dimensions (x,y)
	 *   1 2			//Roomba initial position
	 *   1 0			//Dirt patch, one per line
	 *   2 2
	 * 	 2 3
	 * 	 NNESEESWNWW	//Moving instructions
	 *
	 * To compile:
	 *   g++ -o roombaCleaner roombaCleaner.cpp -std=c++0x
	 *
	 * To execute:
	 *   ./roombaCleaner
	 */

	//Variable declarations
	int roomX, roomY, roombaX, roombaY, patchesCleaned = 0;;
	string instructions;
	map<vector<int>, int> dirtMap; //Dirt coordinates stored in map for fast lookup


	//Parse inputs
	parseInputs(roomX, roomY, roombaX, roombaY, instructions, dirtMap);

	//Run instructions and clean the room
	cleanRoom(instructions, roombaX, roombaY, patchesCleaned, roomX, roomY, dirtMap);


	//Printout results
	cout << roombaX << " " << roombaY << endl; //Roomba final position
	cout << patchesCleaned << endl; //Dirt patches cleaned

}

void parseInputs(int& roomX, int& roomY, int& roombaX, int& roombaY, string& instructions, map<vector<int>, int>& dirtMap) {

	string line;
	vector<int> tmp;
	int breakOut = 0;

	//Reading room dimension, Roomba initial position
	cin >> roomX >> roomY >> roombaX >> roombaY;

	//Determine whether input is integer (dirt coordinates), or string (instructions), then store each accordingly
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
}

void cleanRoom(string instructions, int& roombaX, int& roombaY, int& patchesCleaned, int roomX, int roomY, map<vector<int>, int>& dirtMap) {

	for (int i = 0; i < instructions.length(); i++) {


		/*
		 * If moving out of bounds, then slide against wall (result: no net movements)
		 */
		if (instructions[i] == 'N' && roombaY + 1 <= roomY) {
			roombaY++;
		} else if (instructions[i] == 'E' && roombaX + 1 <= roomX) {
			roombaX++;
		} else if (instructions[i] == 'S' && roombaY - 1 >= 0) {
			roombaY--;
		} else if (instructions[i] == 'W' && roombaX - 1 >= 0) {
			roombaX--;
		}

		vector<int> pos;
		pos.push_back(roombaX);
		pos.push_back(roombaY);
		if (dirtMap.count(pos) > 0) {
			dirtMap.erase(pos); //Erase from known dirt coordinates
			patchesCleaned++;
		}
	}
}
