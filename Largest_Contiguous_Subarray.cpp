#include <iostream>
#include <vector>

using namespace std;

int kadaneMaxCSum(int[], int);

int main() {

	/*
	 * Finding the largest contiguous subarray
	 * 		Aka: Largest contiguous sequence of sum
	 *
	 * Prints the largest contiguous subarray, then
	 *     return the total sum of that sequence.
	 *
	 * Using Kadane's Algorithm
	 *
	 */

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	//int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3, -7, -3, 10, 10, 10, -3, 2}; //Longer test case
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	cout << "Max Contiguous Sum: " << kadaneMaxCSum(arr, arrSize) << endl;

}

int kadaneMaxCSum(int arr[], int length) {

	int max = 0, currentMaxAtIndex = 0;
	vector<int> maxPath, currentPath;

	for (int i = 0; i < length; i++) {
		currentMaxAtIndex = currentMaxAtIndex + arr[i];

		if (currentMaxAtIndex < 0) {
			currentMaxAtIndex = 0; //Reset because it's never going to be part of biggest
					 	 	 	   //And if stayed here will ruin the next positive's sum
			currentPath.clear();
		} else {
			currentPath.push_back(arr[i]);
		}

		if (max < currentMaxAtIndex) {
			max = currentMaxAtIndex;
			maxPath.clear();
			maxPath = currentPath;
		}
	}

	cout << "Largest SubArray Sequence:\n";
	for (int i = 0; i < maxPath.size(); i++) {
		cout << maxPath[i] << " ";
	}
	cout << endl << endl;

	return max;

}
