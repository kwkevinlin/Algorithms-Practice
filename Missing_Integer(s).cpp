#include <iostream>

using namespace std;

int problem1(int[], int, int[], int);

int main() {

	/*
	 * All problems related to missing integer(s)
	 */

	/*
	 * Problem 1:
	 *     Identify the missing integer given two arrays
	 */
	int arr1[] = {1, 2, 3, 4, 6, 7, 8, 9};
	int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "Problem 1: " <<
			problem1(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0])) << endl;


}

int problem1(int arr1[], int length1, int arr2[], int length2) {

	int sum1 = 0, sum2 = 0;
	if (length1 > length2) {
		for (int i = 0; i < length1; i++) {
			if (i < length2) {
				sum2 = sum2 + arr2[i];
			}
			sum1 = sum1 + arr1[i];
		}
	} else {
		for (int i = 0; i < length2; i++) {
			if (i < length1) {
				sum1 = sum1 + arr1[i];
			}
			sum2 = sum2 + arr2[i];
		}
	}

	return sum2 - sum1; //Difference is the missing integer
}
