#include <iostream>
using namespace std;

/*

var image = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1]
];


1 - white
0 - black


 */
int main() {

	int start = -1;
	int startRow;
	int rows = 1;
	int cont = 0;

	int result[4];

	for (int i = 0; i < height; i++) {

		if (start != -1) {
			if (arr[i][start] == 0) { //Potential for 0 rectangle
				rows++;
			}
		}

		for (int j = 0; j < width; j++) {

			if (start == -1) {

				//For each row, keep track of start/end of 0
				if (arr[i][j] == 0) { //True for i = 2, j = 3
					start = j;
					startRow = i;

					//ex: start: i = 2, j = 3

					//Check how long the contiguous 0 goes
					for (int y = j; y < width; y++) {
						if (arr[i][y] == 0) {
							cont++;
						}
						else {
							break;
						}
					}
				}

			}

		}


	}

	cout << "Starting Row: " << startRow << ", column: " << start << ", for " << cont << " values, for " << rows << " rows << endl;
			result[0] = startRow; //y
	
	//Sample output:
	//Starting Row: 4, element: 3, for 3 values, for 1 rows

}


