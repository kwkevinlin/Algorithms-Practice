#include <iostream>

using namespace std;

string longestPalimdrome(string);

int main() {

	/*
	 * Find the Longest Palimdrome in a string
	 *     This solution find the longest palimdrone in O(n^2) time
	 *     Manacher’s Algorithm can be used the find the same thing in O(n), linear time
	 *
	 */

	//string str = "forgeeksskeegfor"; //Palimdrome: "geeksskeeg"
	string str = "foriaifor"; //iai

	cout << longestPalimdrome(str) << endl;

}

string longestPalimdrome(string str) {

	//Check for both EVEN and ODD palimdromes for each "center", ie each [i] in str
	int start, end, max = -1, count = 0;
	int palinStart, length;

	//From 1 to length - 1, use each as center to check for palimdrome
	for (int i = 1; i < str.length() - 1; i++) {

		/* Even sequence */
		start = i - 1;
		end = i;
		while (start < str.length() && end >= 0) {
			if (str[start] == str[end]) {
				count++;

				if (count > max) {
					max = count; 			//Current max palindrome length
					palinStart = i - count;	//Starting index of this palindrome
					length = 2 * count + 1;	//Number of chars
				}
			}
			start--;
			end++;
		}

		max = -1;
		count = 0;

		/* Odd Sequence */
		start = i - 1;
		end = i + 1;


	}

	return str.substr(palinStart, length);

}

