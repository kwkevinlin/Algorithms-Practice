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
	 */

	string input = "[()]";
	//string input = "[{}]()[{{()}}()]";

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
	symbols['{'] = '}';
	symbols['['] = ']';
	symbols['('] = ')';

	//If opening, push onto stack. If closing, check top of stack.
	for (int i = 0; i < str.length(); i++) {
		//If opening
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
			symStack.push(str[i]);
		}
		//If closing
		else {
			if (symStack.top() == str[i]) {
				symStack.pop();
			} else {
				return false;
			}
		}
	}

	return true;

}
