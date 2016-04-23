#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	/*
	 * A building has 100 doors numbered from 1 to 100. A person opened all of the doors,
	 * and next he closes every 2nd door (starting 2, 4). When he finishes all 100 doors,
	 * he opens/closes every 3rd door (3, 6), then every 4th door and so on till the 100th.
	 * Which doors will be closed in the end?
	 *
	 * Solution:
	 *     Doors opened will be 1^2, 2^2, 3^2, ... N   (square)
	 *                          1,   4,   9,   ... 10^10
	 *     Brute-force approach
	 */

	int doors[100];
	fill_n(doors, 100, 1);

	int doorSkip = 2;
	for (int i = 1; i < 100; i++) { //Starting from 2nd door
		for (int j = i; j < 100; j += doorSkip) { //For each doorSkip doors, open/close, then
			if (doors[j] == 0) { //If closed, open
				doors[j] = 1;
			} else {
				doors[j] = 0; //If opened, close
			}
		}
		doorSkip++;
	}

	//Printout result
	for (int i = 0; i < 100; i++) {
		cout << "Door " << i + 1 << ":  ";
		if (doors[i] == 0) {
			cout << " closed\n";
		} else {
			cout << " opened\n";
		}
	}
}
