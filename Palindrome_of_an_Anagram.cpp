#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool palindromeOfAnagram(string);

int main() {

	/*
	 * Determine whether an anagram can be a palindrome as well.
	 *
	 * Example:
	 *     Input: aaabbbb
	 *     Output: YES
	 *     Explanation: A palindrome permutation of the string
	 *                  can be: bbaaabb.
	 *
	 *     Input: cdcdcdcdeeeef
	 *     Output: YES
	 *     Explanation: Palindrome sequence = ddcceefeeccdd
	 *
	 *     Input: cdefghmnopqrstuvw
	 *     Output: NO
	 *     Explanation: No possible palindrome sequence
	 *
	 * Question adapted from:
	 *     HackerRank - Game of Thrones - I
	 *     https://www.hackerrank.com/challenges/game-of-thrones
	 *
	 * Solution:
	 *     Put every character into a map. Then, if there are only
	 *     one or zero character with an odd number of appearances,
	 *     return true. Else (if there are more than one character
	 *     with an odd number of appearances, then return false.
	 *
	 *     This is because to be an even palindrome, there will be
	 *     a matching character for every character in the string
	 *     (thus count of char will be even). To be an odd palindrome,
	 *     there will be one character only (the middle character)
	 *     that will have an odd number of appearances.
	 */

	//string str = "aaabbbb";
	string str = "cdcdcdcdeeeef";
	//string str = "cdefghmnopqrstuvw";

	if (palindromeOfAnagram(str)) {
		cout << "YES\n" << endl;
	} else {
		cout << "NO\n" << endl;
	}

}

bool palindromeOfAnagram(string str) {

	unordered_map<char, int> charMap;
	unordered_set<char> visited;

	//Add every char to map
	for (int i = 0; i < str.length(); i++) {
		charMap[str[i]]++;
	}

	//There should only be 1 or 0 characters with an odd number of appearance
	int oddCount = 0;
	for (int i = 0; i < str.length(); i++) {
		//If haven't counted str[i] before
		if (visited.count(str[i]) < 1 && charMap[str[i]] % 2 == 1) {
			oddCount++;
			visited.insert(str[i]); //Insert to set to mark as counted
		}
	}

	if (oddCount > 1) {
		return false;
	} else {
		return true;
	}

}
