#include <iostream>

using namespace std;

void detectPalindrome(string);

int main() {

	/*
	 * Detect Palindrome words
	 *
	 */

	string str[] = { "sagas",		//True
					 "deleveled",	//True
					 "aibohphobia",	//True
					 "tootsieroll"	//False
	};

	for (int i = 0; i < sizeof(str)/sizeof(str[0]); i++) {
		detectPalindrome(str[i]);
	}

	/*
	 * Even more simple way using STL:
	 * 	   equal(str[i].begin(), str[i].begin() + str[i].length() / 2, str[i].rbegin());
	 */

}

void detectPalindrome(string str) {

	int flag = 1, tmp = str.length() - 1;
	for (int i = 0; i < str.length()/2; i++) {
		if (str[i] != str[tmp]) {
			flag = 0;
			break;
		}
		tmp--;
	}

	if (flag == 1) {
		cout << str << ": palindrome\n";
	} else {
		cout << str << ": NOT palindrome\n";
	}

}
