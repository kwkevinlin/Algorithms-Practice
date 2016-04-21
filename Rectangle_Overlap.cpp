#include <iostream>
#include <sstream>

using namespace std;

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
	//string input = "(1,1),(4,4),(4,1),(1,4),(4,2),(3,2),(4,1),(3,1)"; //Quadrant 1 - Perfect overlap
	//				012345678910         21  25
	//string input = "(1,1),(1,4),(4,4),(4,1),(3,2),(5,2),(3,0),(5,0)"; //Quadrant 1
	//string input = "(-1,1),(-4,1),(-4,4),(-1,4),(-3,1),(-4,2),(-3,2),(-4,1)"; //Quadrant 2
	//string input = "(-1,-1),(-1,-4),(-4,-4),(-4,-1),(-5,0),(-3,0),(-5,-2),(-3,-2)"; //Quadrant 3
	//string input = "(1,-1),(1,-4),(4,-4),(4,-1),(3,0),(5,0),(3,-2),(5,-2)"; //Quadrant 4
	string input = "(1,1),(4,1),(1,-2),(4,-2),(3,-1),(5,-1),(3,-3),(5,-3)"; //Quadrant 1 & 4 intersect


	/*
	 * Starting new algorithm
	 */

	pair<int, int> rect1[4], rect2[4];
	int index = 0, count = 0, prevI;
	string prev;
	stringstream ss;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(' || input[i] == ',') {

			prevI = i;
			for (i = i + 1; i < input.length(); i++) { //Look ahead until stopping symbol
				if (input[i] == ',' || input[i] == ')' || input[i] == '(') {
					i--;
					break;
				} else {
					ss << input[i];
				}
			}

			if (prevI == i) { //Means encountered the comma in between ),(
				continue;
			}

			count++;
			if (count % 2 == 0) { //Insert into rect arrays
				if (index <= 4) {
					rect1[index] = make_pair(stoi(prev), stoi(ss.str()));
				} else {
					rect2[index % 4] = make_pair(stoi(prev), stoi(ss.str()));
				}
				index++;
			} else {
				prev = ss.str();
			}
			ss.str("");
		}
	}

	for (auto kv : rect1) {
		cout << kv.first << ", " << kv.second << endl;
	}




	//	// Storing in unordered set to avoid dealing with duplicates
	//	set<int> X1;
	//	set<int> Y1;
	//	set<int> X2;
	//	set<int> Y2;
	//	int count = 0;
	//	for (int i = 0; i < input.length(); i++) {
	//
	//		//Only parse if it is a number
	//		if (input[i] != '(' && input[i] != ')' && input[i] != ',' && input[i] != '-') {
	//
	//			if (count < 8) { //Rectangle 1
	//				if (count % 2 == 0) { //X coordinate
	//					setInsert(X1, input[i], input[i-1]);
	//				} else { //Y coordinate
	//					setInsert(Y1, input[i], input[i-1]);
	//				}
	//			} else { //Rectangle 2
	//				if (count % 2 == 0) {
	//					setInsert(X2, input[i], input[i-1]);
	//				} else {
	//					setInsert(Y2, input[i], input[i-1]);
	//				}
	//			}
	//			count++;
	//		}
	//
	//	}
	//
	//	/* Range intercept will be:
	//	 *
	//	 * For X1: X1[0] <--> X1[1]
	//	 * 		 :  1   <----> 4
	//	 */
	//
	//	/*
	//	 * Rethink this. Currently converting set to array to use [] operator
	//	 */
	//	array<int, 2> rangeX1, rangeX2, rangeY1, rangeY2;
	//	copy(X1.begin(), X1.end(), rangeX1.begin());
	//	copy(Y1.begin(), Y1.end(), rangeY1.begin());
	//	copy(X2.begin(), X2.end(), rangeX2.begin());
	//	copy(Y2.begin(), Y2.end(), rangeY2.begin());
	//
	//	int overlap = 0;
	//
	//	/*
	//	 * Changed && to || in overlap detection
	//	 *    Check to make sure its logical
	//	 */
	//
	//	//Check if overlap
	//	cout << rangeX2[0] << " >= " << rangeX1[0] <<  " || " << rangeX2[1] << " <= " << rangeX1[1] << endl;
	//	if (rangeX2[0] >= rangeX1[0] || rangeX2[1] <= rangeX1[1]) {
	//		cout << "X overlap\n";
	//		cout << rangeY2[0] << " >= " << rangeY1[0] <<  " || " << rangeY2[1] << " <= " << rangeY1[1] << endl;
	//		if (rangeY2[0] >= rangeY1[0] | rangeY2[1] <= rangeY1[1]) {
	//			cout << "Y overlap\n";
	//			overlap = 1;
	//		}
	//	}
	//	cout << endl;
	//
	//	//Check area of overlap
	//	if (overlap == 1) {
	//		/*
	//		 * A. Get area of Rect1
	//		 * B. Determine area of overlap
	//		 * C. Get B/A
	//		 */
	//
	//		// A. Get area of Rect1
	//		int areaRect1 = ( rangeX1[1] - rangeX1[0] ) * ( rangeY1[1] - rangeY1[0] );
	//		cout << "Rect1 Area: " << areaRect1 << endl;
	//
	//		// B. Determine area of overlap
	//
	//		/* Check which: [0] or [1] (or both) is inside big rectangle
	//		 * This can be combined to "Check if overlap" later	*/
	//		int XSmall = 0, XBig = 0;
	//		if (rangeX2[0] >= rangeX1[0]) {
	//			XSmall = 1;
	//			cout << "SmallX in\n";
	//		}
	//		if (rangeX2[1] <= rangeX1[1]) {
	//			XBig = 1;
	//			cout << "BigX in\n";
	//		}
	//
	//		/*
	//		 * BUG LOOK HERE
	//		 *    Need to add abs() in XOverlap
	//		 */
	//		int XOverlap;
	//		//3 Cases. Again, can be combined later
	//		if (XSmall == 1 && XBig == 0) { //Only X[0] is overlapped in Rect1
	//			XOverlap = rangeX1[1] - rangeX2[0];
	//		} else if (XSmall == 0 && XBig == 1) { //Only X[1] overlapped
	//			XOverlap = rangeX2[1] - rangeX1[0];
	//		} else { //Both overlapped
	//			//Full length - (right extra space) - (left extra space)
	//			XOverlap = (rangeX1[1] - rangeX1[0]) - (rangeX1[1] - rangeX2[1]) - (rangeX1[0] - rangeX2[0]);
	//		}
	//		cout << "XOverlap: " << XOverlap << endl;
	//	}
	//
	//
	//}
	//
	//void setInsert(set<int> &setCoor, char current, char prev) {
	//
	//	if (prev == '-') { //Is negative number
	//		setCoor.insert((current - '0') * -1);
	//	} else { //Positive
	//		setCoor.insert(current - '0');
	//	}
}
