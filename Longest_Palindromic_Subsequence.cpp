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

	string str = "forgeeksskeegfor"; //Palimdrome: "geeksskeeg"

	cout << longestPalimdrome(str) << endl;

}

string longestPalimdrome(string str) {

	//From 1 to length - 1, use each as center to check for palimdrome
	for (int i = 1; i < str.length() - 1; i++) {

		//Check for both EVEN and ODD palimdromes


	}

	return "in progress";

}

