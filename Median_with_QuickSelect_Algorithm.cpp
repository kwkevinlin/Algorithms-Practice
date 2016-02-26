#include <iostream>

using namespace std;

void selection(int[], int, int, int, int);

int main() {

	/*
	 * Prompt:
	 * 		Find the median value of an unsorted number sequence
	 *
	 * Solution:
	 * 		Using the QuickSelect Algorithm, set K (Kth smallest element) as
	 * 		floor(N/2) where N is the number of numbers in the sequence
	 *
	 * 	Complexity:
	 * 		A divide and conquer algorithm with linear time complexity, O(n)
	 */

	int arr[] = {2, 36, 5, 21, 8, 13, 11, 20, 5, 4, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int medianK = size / 2 - 1;

	selection(arr, medianK, size, 0, size - 1);

}

void selection(int arr[], int k, int size, int l, int r) {

	int mid = arr[k];
	cout << mid << endl;

	//Sort L (<) and R (>) with mid as pivot
	while (l < r) {

		while (arr[l] < mid) {
			l++;
		}
		//cout << "\nSwap " << arr[l];

		while (arr[r] > mid) {
			r--;
		}
		//cout << "/twith " << arr[r];

		int tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;

	}


	//Array check
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

}
