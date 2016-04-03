#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool symbolChecker(string);

int main() {

	/*
	 * Match the braces and verify whether all the opening braces have the closing braces in the right order.
	 *
	 * For example:
	 *     Input: [{}]()[{{()}}()]
	 *     Output: Yes
	 *
	 *     Input: [{}]({{()}}()]
	 *     Output: No
	 *
	 * Solution:
	 *     Loop through string. If [i] is an opening symbol, push it onto the stack. If it is a closing
	 *     symbol, check to see if it corresponds to the element on the top of the stack (uses a map here).
	 *     If it doesn't, return false. Else, at the end of the loop, return true.
	 *
	 */

	string input = "[{}]()[{{()}}()]"; //Match
	//string input = "[{}]({{()}}()]"; //No match

	if (symbolChecker(input)) {
		cout << "Symbols match!\n";
	} else {
		cout << "Symbols do NOT match!\n";
	}

}

bool symbolChecker(string str) {

	stack<char> symStack;
	unordered_map<char, char> symbols;

	//Storing complements to hash table
	symbols['}'] = '{';
	symbols[']'] = '[';
	symbols[')'] = '(';

	//If opening, push onto stack. If closing, check top of stack.
	for (int i = 0; i < str.length(); i++) {
		//If opening
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
			symStack.push(str[i]);
		}
		//If closing
		else {
			if (symStack.top() == symbols[str[i]]) {
				symStack.pop();
			} else {
				return false;
			}
		}
	}

	return true;

}
