#include <iostream>
#include <unordered_map>

using namespace std;

bool palindromeOfAnagram(string);

int main() {

	/*
	 * Determine whether an anagram can be a palindrome as well.
	 *
	 * Example:
	 *     Input: aaabbbb
	 *     Output: Yes
	 *     Explanation: A palindrome permutation of the string
	 *                  can be: bbaaabb.
	 *
	 *     Input: cdcdcdcdeeeef
	 *     Output: Yes
	 *     Explanation: Palindrome sequence = ddcceefeeccdd
	 *
	 *     Input: cdefghmnopqrstuvw
	 *     Output: No
	 *     Explanation: No possible palindrome sequence
	 *
	 * Question adapted from:
	 *     HackerRank - Game of Thrones - I
	 *     https://www.hackerrank.com/challenges/game-of-thrones
	 */

	string str = "aaabbbb";

	if (palindromeOfAnagram(str)) {
		cout << "YES\n" << endl;
	} else {
		cout << "NO\n" << endl;
	}

}

bool palindromeOfAnagram(string str) {

	unordered_map<char, int> charMap;

	//Add every char to map
	for (int i = 0; i < str.length(); i++) {
		charMap[str[i]]++;
	}

	int oddCount = 0;

	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << ", " << charMap[str[i]] << endl;
		if (charMap[str[i]] % 2 == 1) {
			oddCount++;
		}
	}

	if (oddCount > 1) {
		return false;
	} else {
		return true;
	}

}
