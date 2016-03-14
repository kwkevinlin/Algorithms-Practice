#include <iostream>
#include <set>
#include <array>

using namespace std;

void setInsert(set<int>&, char, char);

int main() {

	/*
	 * Given a spring: "(1,2),(1,1)..." that represents 8 coordinates, the first four is for
	 * the first rectangle, the next four is for the second rectangle.
	 *
	 * Determine 1). if the rectangles overlap, and
	 * 			 2). if 1). is true, what percent of the first rectangle is overlapped
	 *
	 * For example:
	 *     Input string: "(1,1),(4,4),(4,1),(1,4),(4,2),(3,2),(4,1),(3,1)" (coordinates are
	 *     				 in no order except for first four = 1st rectangle, ... etc)
	 *
	 *         Visualized: (Rect 1 = Big one, Rect 2 = Small one)
	 *
	 *         			 4 |-----|
	 *         			 3 |     |
	 *         			 2 |    _|
	 *         			 1 |___|_|
	 *         			   1 2 3 4
	 *     Output:
	 *     		1). Yes
	 *     		2). 1/9 = 11% overlapped
	 *
	 */
	//				 x y   x y   x y   x y   x y   x y   x y   x y
	//string input = "(1,1),(4,4),(4,1),(1,4),(4,2),(3,2),(4,1),(3,1)";
	//				012345678910         21  25
	string input = "(-1,1),(-4,1),(-4,4),(-1,4),(-3,1),(-4,2),(-3,2),(-4,1)";

	// Storing in unordered set to avoid dealing with duplicates
	set<int> X1;
	set<int> Y1;
	set<int> X2;
	set<int> Y2;
	int count = 0;
	for (int i = 0; i < input.length(); i++) {
		//		if (i == 1 || i == 7 || i == 13 || i == 19) {
		//			X1.insert(input[i] - '0');
		//		}
		//		else if (i == 3 || i == 9 || i == 15 || i == 21) {
		//			Y1.insert(input[i] - '0');
		//		}
		//		else if (i == 25 || i == 31 || i == 37 || i == 43) {
		//			X2.insert(input[i] - '0');
		//		}
		//		else if (i == 27 || i == 33 || i == 39 || i == 45) {
		//			Y2.insert(input[i] - '0');
		//		}

		if (input[i] != '(' && input[i] != ')' && input[i] != ',' && input[i] != '-') {

			if (count < 8) { //Rectangle 1
				if (count % 2 == 0) { //X coordinate
					setInsert(X1, input[i], input[i-1]);
				} else { //Y coordinate
					setInsert(Y1, input[i], input[i-1]);
				}
			} else { //Rectangle 2
				if (count % 2 == 0) {
					setInsert(X2, input[i], input[i-1]);
				} else {
					setInsert(Y2, input[i], input[i-1]);
				}
			}
			count++;
		}

	}

	/* Range intercept will be:
	 *
	 * For X1: X1[0] <--> X1[1]
	 * 		 :  1   <----> 4
	 */

	/*
	 * Rethink this. Currently converting set to array to use [] operator
	 */
	array<int, 2> rangeX1, rangeX2, rangeY1, rangeY2;
	copy(X1.begin(), X1.end(), rangeX1.begin());
	copy(Y1.begin(), Y1.end(), rangeY1.begin());
	copy(X2.begin(), X2.end(), rangeX2.begin());
	copy(Y2.begin(), Y2.end(), rangeY2.begin());

	int overlap = 0;
	//Check if overlap
	if (rangeX2[0] >= rangeX1[0] && rangeX2[1] <= rangeX1[1]) {
		cout << "X overlap\n";
		cout << rangeY2[0] << " >= " << rangeY1[0] <<  " && " << rangeY2[1] << " <= " << rangeY1[1] << endl;
		if (rangeY2[0] >= rangeY1[0] && rangeY2[1] <= rangeY1[1]) {
			cout << "Y overlap\n";
			overlap = 1;
		}
	}


}

void setInsert(set<int> &setCoor, char current, char prev) {

	if (prev == '-') { //Is negative number
		setCoor.insert((current - '0') * -1);
	} else { //Positive
		setCoor.insert(current - '0');
	}
}
