#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int byLoop(int[], int);
int bySort(int[], int);

int main() {

	/*
	 * Find the 2nd largest element in an array
	 *
	 *    Method 1: Single array to find 2nd largest in 1 loop, O(n) time
	 *    Method 2: stl::sort() to sort array, then access second to last element, O(n log(n)) time
	 */

	//Assuming no negative numbers
	int arr[] = {3, 8, 1, 0, 4, 9, 1, 3, 6, 8, 5, 10};

	int length = sizeof(arr)/sizeof(arr[0]);

	int secondMax;

	//Method 1 - By loop
	secondMax = byLoop(arr, length);
	cout << secondMax << endl;

	//Method 2 - By Sort
	secondMax = bySort(arr, length);
	cout << secondMax << endl;


}

int byLoop(int arr[], int length) {

	int max = -1, secondMax = -1;

	for (int i = 0; i < length; i++) {

		if (arr[i] > secondMax) {
			if (arr[i] > max) {
				//Then update max and secondMax = current max;
				secondMax = max;
				max = arr[i];
			} else {
				//But not greater than max, so second greatest
				secondMax = arr[i];
			}
		}

	}

	return secondMax;
}

int bySort(int arr[], int length) {

	//Pointers can act as iterators, so you just need pointers to the beginning and just past the end of the array.
	sort(arr, arr + length);

	return arr[length - 2];
}
