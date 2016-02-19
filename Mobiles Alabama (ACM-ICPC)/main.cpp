/*
 * Author: Kevin Lin
 * ACM-ICPC 2007 Mid-Atlantic Regionals
 * Problem B - Mobiles Alabama
 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <iomanip>

#include "bar.h"
#include "decoration.h"

using namespace std;

int main () {

	/*
	 * The program reads in from input.txt, and stores each character as a string in a stack (inputStack).
	 * Starting from the top of inputstack, we push everything onto another stack (storageStack), and pop
	 * them off inputStack accordingly when storageStack is done processing them (explained in next sentence).
	 * We repeat this process until we see a "(" string, which signifies the start of a parenthesis. So we pop
	 * that off from storageStack, and check what the next character is.
	 * If it is:
	 * 		"D" : We pop "D", then use the value on storageStack.top() which is the weight of the decoration,
	 * 			  and create a new decoration class object and push that onto dec<vector>. It will be used when
	 * 			  we process "B". Dec<vector> contains all of the weights that will be used for calculation. The
	 * 			  last two will always be the ones used for calculations.
	 * 		"B" : This is where we really get the solution to the question. We pop "B", then using the next two
	 * 			  elements on the top of the stack (bar ID and length), we create a bar class object and put that
	 * 			  onto another vector, bars<vector>. A vector doesn't necessarily need to be used here because
	 * 			  we're only processing one bar at a time, and we won't need previous bars for future calculations
	 * 			  (only the weight of the bar will be needed, which is stored in dec<vector>. It would probably be
	 * 			  more efficient to just use a single bar object, and delete/or modify the instance everytime we
	 * 			  need to.
	 *
	 * 			  How the Math was Done:
	 * 			  Every time "B" is being processed, we will take the specifications of the weights from the top
	 * 			  of the dec<vector>, so dec[dec.size() - 1].getWeight(), and also for dec.size() - 2.
	 * 			  As we know,
	 * 			  		L1 + L2 = X, where X is the length of the bar, and is given (ex: 2)
	 * 			  We also know from the worksheet that,
	 * 			  		L1W1 = L2W2
	 * 			  So let's take L1, and try to substitute that into the first equation. Trying to separate L1,
	 * 			  		L1 = ( L2W2 ) / W1
	 * 			  Let Tweight = W2 / W1, since
	 * 			  		L1 = L2 * (W2/W1)
	 *			  Thus,
	 * 			  		L1 = L2 * Tweight
	 * 			  Using the new value of L1,
	 * 			  		L1 + L2 = 2
	 * 			  Substitute in from above (L1 = L2 * Tweight),
	 * 			  		Tweight * L2 + L2 = 2
	 * 			  If Tweight = 3, then:
	 * 			  		3 * L2 + L2 = 2
	 * 			  		4L2 = 2
	 * 			  		L2 = 1/2
	 * 			  With L2 known,
	 * 			  		L1 + L2 = 2
	 * 			  		L1 + 1/2 = 2
	 * 			  		L1 = 3/2
	 * 			  So we output the value of L2 since that is the smaller of the two:
	 * 			  		Bar Y must be tied 0.5 from one end
	 * 			  We use the same technique to solve for all the bars in the input, from back to front.
	 *
	 * 			  Once the bar is finished being calculated, we delete the top two elements of dec<vector> (since
	 * 			  those were used for the calculation we just finished), and write the new combined weight of the
	 * 			  two elements we popped onto the vector. This sets up dec<vector> so that the same algorithm can
	 * 			  be used for the other bars, if there are any.
	 *
	 */

	stack<string> inputStack;
	stack<string> storageStack;
	vector<decoration> dec;
	vector<bar> bars; //Notice bars (vector) vs bar (class)

	/*
	 * Part 1: Parsing Input
	 */
	ifstream input("input1.txt"); //Use "input2.txt" for more intense testing of corner cases
	string in, concat;
	while (input >> in) {
		if (in.length() > 1 && in.find(".") == -1) {
			//Reading in as string will read symbols together, ex: ((( or (B
			//Want to split them up, but don't split numbers, ex: 2.0 or 3.1
			for (int i = 0; i < in.length(); i++) {
				cout << in[i] << " ";
				inputStack.push(string(1, in[i]));
			}
		} else {
			//This section splits strings if:
			//Both float and ( or ) exists, ex: 2.0) or (3.5 (notice no space)
			if (in.find(".") != -1 && (in.find(")") != -1 || in.find("(") != -1) ) {
				for (int i = 0; i < in.length(); i++) {
					//Inside these loops, if ) or (, push. Before push though,
					//push everything before that (if it exists)
					if (in[i] == ')') {
						if (concat.length() > 0) {
							cout << concat << " ";
							inputStack.push(concat);
							concat = "";
						}
						inputStack.push(string(1, in[i]));
						cout << inputStack.top() << " ";
					}
					else if (in[i] == '(') {
						if (concat.length() > 0) {
							cout << concat << " ";
							inputStack.push(concat);
							concat = "";
						}
						inputStack.push(string(1, in[i]));
						cout << inputStack.top() << " ";
					}
					else {
						//So if we see 2.0), then store 2.0 in concat first, then
						//when we see ), we will push both 2.0 and ) in the above if statements
						concat = concat + string(1, in[i]);
					}
				}
				//The following occurs if parenthesis () before float
				//Ex: (2.0 , without this, 2.0 will be in concat but won't be pushed.
				if (concat.length() != 0) {
					inputStack.push(concat);
					cout << inputStack.top() << " ";
				}
			}
			else {
				cout << in << " ";
				inputStack.push(in);
			}
		}
	}
	cout << endl << endl;

/*
    //If ever want to print out inputStack for debug/testing
	while (!inputStack.empty()) {
		cout << inputStack.top() << " ";
		inputStack.pop();
	}
	cout << endl << endl;
*/

	/*
	 * Part 2: Calculating Bar Lengths
	 */
	float weightTempFloat, length2Total, length1, length2;
	int tempID;
	int barIndex = 0;
	while (!inputStack.empty()) {
		in = inputStack.top();
		//At start, put everything to storageStack
		//cout << "Reading in: " << in << endl;
		storageStack.push(in);

		if (in == "(") { //Only parse if "("
			storageStack.pop(); //Pop off "("
			//Default runs this
			if (storageStack.top() != ")") {//If not ). Ignore, since if ( ), then its end of input
				//cout << "Inside with " << storageStack.top() << endl;
				if (storageStack.top() == "D") {
					storageStack.pop(); //Pop off D to access weight
					dec.push_back(decoration(stof(storageStack.top()))); //Creates temporary
					//cout << "Top: " << storageStack.top() << endl;
					storageStack.pop(); //Pop off 2.0
					//cout << "Top: " << storageStack.top() << endl;
					storageStack.pop(); //Pop off )

				}
				else if (storageStack.top() == "B") {
					storageStack.pop(); //Pop off B
					tempID = stoi(storageStack.top());
					storageStack.pop(); //Pop off bar ID
					bars.push_back(bar(tempID, stof(storageStack.top())));
					storageStack.pop(); //Pop off weight
					//cout << "Size check: " << storageStack.size() << " " << storageStack.top() << endl;
					//storageStack.pop(); //Pop off )
					//cout << "Size check: " << storageStack.size() << endl;

					storageStack.pop(); //Pop off )

					//Once reach bar, then means decorations are ready, so can start calculating
					//cout << "\nNumber of bars: " << bars.size() << endl;
					barIndex = bars.size() - 1; //Can replace using vector since there's really no need for one

					//Doing calculations
					//cout << "Using weights: " << dec[dec.size() - 2].getWeight() << ", " << dec[dec.size() - 1].getWeight() << endl;
					length2Total = 1 + (dec[dec.size() - 2].getWeight()/dec[dec.size() - 1].getWeight()); // L1+L2 = 2, but L1 = 2L2 so 3L2 = 2. Hardcoded 1 because L2 will always be by itself
					//cout << length2Total << endl;
					length2 = bars[barIndex].getLength()/length2Total;
					cout << "Length2 = " << length2 << endl;
					length1 = bars[barIndex].getLength() - length2;
					cout << "Length1 = " << length1 << endl;

					if (length1 < length2 )
						cout << "\tBar " << bars[barIndex].getBarID() << " must be tied " << fixed << setprecision(1) << length1 << " from one end." << endl;
					else
						cout << "\tBar " << bars[barIndex].getBarID() << " must be tied " << fixed << setprecision(1) << length2 << " from one end." << endl;

					//Now, write them back to decoration so next bar can use

					//Position shouldn't matter, so erase both and push new total weight (W1 + W2) onto dec vector
					weightTempFloat = dec[dec.size() - 2].getWeight() + dec[dec.size() - 1].getWeight();
					//dec.clear(); //Can't clear because don't know how nested
					dec.pop_back();
					dec.pop_back();
					dec.push_back(decoration(weightTempFloat));


					//So every time, dec<vector> will only have 2 items, setting up for future calculations

				}
			}
		}
		inputStack.pop();
	}
}
