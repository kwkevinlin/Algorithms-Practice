#include <iostream>

using namespace std;


/*
	Prompt:
	Given a 2D array, identify the position and shape of the 0-bit rectangle.

	var image = [
	  [1, 1, 1, 1, 1, 1, 1],
	  [1, 1, 1, 0, 0, 0, 1],
	  [1, 1, 1, 0, 0, 0, 1],
	  [1, 1, 1, 1, 1, 1, 1],
	  [1, 1, 1, 1, 1, 1, 1]
	];

	Note: Only one such 0-bit rectangle exists in the image array.

 */

int height = 5;
const int width = 7;

void detectRect(int[][width], int[]);

int main() {

	//Populating sample array
	int image[height][width] = {
			{1, 1, 1, 1, 1, 1, 1}, //Row 0
			{1, 1, 1, 0, 0, 0, 1}, //Row 1
			{1, 1, 1, 0, 0, 0, 1}, //Row 2
			{1, 1, 1, 1, 1, 1, 1}, //Row 3
			{1, 1, 1, 1, 1, 1, 1}  //Row 4
	};

	int result[4];
	detectRect(image, result);
	cout << "Start Row: " << result[0] << endl <<
			"Start Col: " << result[1] << endl <<
			"For: " << result[2] << " Columns\n" <<
			"And: " << result[3] << " Rows\n";
}

void detectRect(int arr[][width], int result[]) {
	int startRow;		//Starting row
	int startCol = -1; 	//Starting column
	int cont = 0;		//Number of consecutive 0s
	int rows = 1;		//Number of rows


	for (int i = 0; i < height; i++) {

		if (startCol != -1) {
			if (arr[i][startCol] == 0) {
				rows++;
			}
		}

		for (int j = 0; j < width; j++) {

			//Only check if no previous 0s encountered
			if (startCol == -1) {

				//If found the start of the 0-bit rectangle
				if (arr[i][j] == 0) {
					startCol = j;
					startRow = i;

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

	//0-bit rectangle coordinate description
	result[0] = startRow; 	//y
	result[1] = startCol;   //x
	result[2] = cont;     	//width
	result[3] = rows;     	//height


}


