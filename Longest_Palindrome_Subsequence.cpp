#include <iostream>

using namespace std;

string longestPalindrome(string);

int main() {

	/*
	 * Find the Longest Palindrome in a string
	 *     This solution find the longest palindrome in O(n^2) time
	 *     Manacher’s Algorithm can be used the find the same thing in O(n), linear time
	 *
	 */

	string str = "forgeeksskeegfor"; //Palimdrome: "geeksskeeg"
	//string str = "foriifor"; //ii - Even

	cout << "Longest palindromic subsequence: \"" << longestPalindrome(str) << "\"" << endl;

}

string longestPalindrome(string str) {

	//Check for both EVEN and ODD palindromes for each "center", ie each [i] in str
	int start, end, count, max = -1;
	int palinStart, length;

	//From 1 to length - 1, use each as center to check for palindrome
	for (int i = 1; i < str.length() - 1; i++) {

		cout << "Loop " << i << ": " << str[i] << endl;

		/* Even sequence */
		start = i - 1;
		end = i;
		count = 0;
		while (start >= 0 && end < str.length()) {
			if (str[start] == str[end]) {
				cout << "    Match-> " << str[start] << " : " << str[end] << endl;
				count++;

				if (count > max) {
					max = count; 			//Current max palindrome length
					palinStart = i - count;	//Starting index of this palindrome
					length = 2 * count;	//For str.substring(palinStart, length)
					cout << "\t    Current palin length: " << length << endl;
				}
				start--;
				end++;
			} else {
				break;
			}

		}

		count = 0;

		/* Odd Sequence */
		start = i - 1;
		end = i + 1;

	}

	cout << "\nPalinStart: " << palinStart << ", length: " << length << endl << endl;

	return str.substr(palinStart, length);

}

