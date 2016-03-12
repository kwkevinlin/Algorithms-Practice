#include <iostream>
#include <unordered_set>

using namespace std;

void getUnion(int[], int[], int);
void getIntersection(int[], int[], int);

int main() {

	/*
	 * Union and Intersection of two arrays
	 *
	 * Definitions:
	 *     Union = All of in arr1, arr2, and in both.
	 *     Intersection = Only those in both arr1 and arr2.
	 *
	 * Notes:
	 *     Union and intersection contains no duplicate.
	 *     Unordered_set bucket outputs are unordered.
	 */

	int arr1[] = {7, 5, 3, 4, 9, 1};
	int arr2[] = {2, 3, 9, 0, 6, 8};

	int length = sizeof(arr1)/sizeof(arr1[0]);

	getUnion(arr1, arr2, length);
	getIntersection(arr1, arr2, length);

}

void getUnion(int arr1[], int arr2[], int length) {

	unordered_set<int> setUnion;

	//Not sure yet the error of range insert
	//setUnion.insert(arr1->begin(), arr1.end());

	for (int i = 0; i < length; i++) {
		setUnion.insert(arr1[i]);
		setUnion.insert(arr2[i]);
	}

	//Union printout
	cout << "Unions: ";
	for (auto kv : setUnion) {
		cout << kv << " ";
	}
	cout << endl;
}

void getIntersection(int arr1[], int arr2[], int length) {


}
