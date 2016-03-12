#include <iostream>
#include <unordered_set>
#include <iterator>

using namespace std;

void getUnion(int[], int[], int);
void getIntersection(int[], int[], int);

int main() {

	/*
	 * Union and Intersection of two arrays
	 *
	 * Definitions:
	 *     Union = All of arr1, arr2, and included in both.
	 *     Intersection = Only those in both arr1 and arr2.
	 *
	 * Notes:
	 *     Union and intersection contains no duplicate
	 *     Unordered_set bucket outputs are unordered
	 *
	 * Input:
	 *     array1 = {7, 5, 3, 4, 9, 1}
	 *     array2 = {2, 3, 0, 9, 6, 8}
	 *
	 * Output:
	 *     Union: 0 1 2 3 4 5 6 7 8 9
     *     Intersection: 3 9
	 */

	int arr1[] = {7, 5, 3, 4, 9, 1};
	int arr2[] = {2, 3, 0, 9, 6, 8};

	int length = sizeof(arr1)/sizeof(arr1[0]);

	getUnion(arr1, arr2, length);
	getIntersection(arr1, arr2, length);

}

void getUnion(int arr1[], int arr2[], int length) {

	unordered_set<int> setUnion;

	for (int i = 0; i < length; i++) {
		setUnion.insert(arr1[i]);
		setUnion.insert(arr2[i]);
	}

	//Union printout
	cout << "Union: ";
	for (auto kv : setUnion) {
		cout << kv << " ";
	}
	cout << endl;
}

void getIntersection(int arr1[], int arr2[], int length) {

	unordered_set<int> setInter;

	for (int i = 0; i < length; i++) {
		setInter.insert(arr1[i]);
	}

	cout << "Intersection: ";
	for (int i = 0; i < length; i++) {
		if (setInter.count(arr2[i]) > 0) { //If key exists
			cout << arr2[i] << " ";
		}
	}
	cout << endl;

}
