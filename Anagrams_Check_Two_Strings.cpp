#include <iostream>
#include <unordered_map>

using namespace std;

int isAnagram(string, string);

int main() {

	//Check if two strings (words) are anagram O(1) space and O(n) time
	/*
	 * Time  Complexity: O(3n) -> O(n)
	 * Space Complexity: O(26) worst -> O(1)
	 *
	 * Space complexity is assuming the strings only represent words
	 * (ie. 26 characters in the alphabet)
	 */

	string str1 = "iceman";
	string str2 = "cinema";

	cout << "Str1: " << str1 <<
			"\nStr2: " << str2 << endl << endl;

	if (isAnagram(str1, str2) == 1)
		cout << "Is Anagram: True\n";
}

int isAnagram(string str1, string str2) {

	unordered_map<char, int> hash;
	int isAnagram = 1;

	//Storing to hash
	for (int i = 0; i < str1.length(); i++) {
		hash[str1[i]]++;
	}

	//Checking for anagram
	for (int i = 0; i < str2.length(); i++) {
		if (hash.count(str2[i]) > 0) {
			hash[str2[i]]--;
		} else {
			cout << "Is Anagram: False\n";
			isAnagram = 0;
			break;
		}
	}

	if (isAnagram == 1) {
		for (int i = 0; i < str1.length(); i++) {
			if (hash[str1[i]] != 0) {
				cout << "Is Anagram: False\n";
				isAnagram = 0;
				break;
			}
		}
	}

	if (isAnagram == 1)
		return 1;
	else
		return 0;

}


