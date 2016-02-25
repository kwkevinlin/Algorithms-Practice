#include <iostream>

using namespace std;

int kadaneMaxCSum(int[], int);

int main() {

	/*
	 * Finding the largest contiguous subarray
	 * 		Aka: Largest contiguous sequence of sum
	 *
	 * Using Kadane's Algorithm
	 */

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	cout << "Max Contiguous Sum: " << kadaneMaxCSum(arr, arrSize);

}

int kadaneMaxCSum(int arr[], int length) {

	int max = 0, currentMaxAtIndex = 0;

	for (int i = 0; i < length; i++) {
		currentMaxAtIndex = currentMaxAtIndex + arr[i];
		if (currentMaxAtIndex < 0) {
			currentMaxAtIndex = 0; //Reset because it's never going to be part of biggest
					 	 	 	   //And if stayed here will ruin the next positive's sum
		}
		if (max < currentMaxAtIndex) {
			max = currentMaxAtIndex;
		}
	}

	return max;
}
