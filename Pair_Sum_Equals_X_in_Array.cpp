#include <iostream>
#include <unordered_map>

using namespace std;


int main() {

	/*
	 * Given an int array, find if there is a pair of
	 * for which the sum of the pair equals an integer
	 * in the array itself
	 *
	 * Complexity:
	 *     Time: O(n^2) because of pairing. Hash check
	 *           is O(1) constant time.
	 */

	int arr[] = {4, 6, 2, 8, 7, 1};

	//Store each int in set for easier lookup
	unordered_map<int, int> hash;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		hash[arr[i]] = 1;
	}

	//Make each pairs and check if sum is in the set
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		for (int j = i + 1; j < sizeof(arr)/sizeof(arr[0]); j++) {
			if (hash.count(arr[i] + arr[j]) >= 1) { //If found in hash
				cout << arr[i] << " + " << arr[j] << " = " << arr[i] + arr[j] << endl;
			}
		}
	}

}
