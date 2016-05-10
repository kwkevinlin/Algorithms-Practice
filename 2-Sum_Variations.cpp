#include <iostream>
#include <unordered_map>

using namespace std;

int main () {

	/*
	 * 2-Sum: Given a sorted array, write a program to decide if two elements sum up to a third
	 */

	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	/*
	 * If the "third" value is any element in the array
	 */
	//Storing array into map for fast lookup
	unordered_map<int, int> map;
	for (int i = 0; i < 10; i++) {
		map[arr[i]];
	}

	//Check if pair sum belongs in map
	int sum;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			sum = arr[i] + arr[j];
			if (map.count(sum) > 0) {
				cout << arr[i] << " + " << arr[j] << " -> " << sum << endl;
			}
		}
	}

	cout << endl << endl;
	/*
	 * If sum to find is given
	 */

	int given = 5;
	for (int i = 0; i < 10; i++) {
		if (map.count(given - arr[i]) > 0) {
			if ((given-arr[i]) <=  arr[i]) {
				break; //Rest are duplicate pairs
			} else {
				cout << arr[i] << " + " << (given - arr[i]) << " -> " << given << endl;
			}
		}
	}

}

