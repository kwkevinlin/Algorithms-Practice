#include <iostream>
#include <vector>

using namespace std;

int main () {

	/*
	 * Merge two sorted lists
	 *
	 * Complexity: O(n)
	 */

	int arr1[7] = {1, 2, 3, 4, 7, 9, 10};
	int arr2[7] = {2, 3, 4, 6, 8, 11, 12};

	int merged[14];

	//Merge into new list (vector)
	int p1 = 0, p2 = 0, index = 0;
	while(1) {
		//Use merging technique as seen in mergesort
		if (arr1[p1] <= arr2[p2]) {
			merged[index] = (arr1[p1]);
			p1++;
		} else {
			merged[index] = (arr2[p2]);
			p2++;
		}
		index++;

		//Push rest of remaining elements
		if (p1 == 7) {
			for (int i = p2; i < 7; i++) {
				merged[index] = (arr2[i]);
				index++;
			}
			break;
		} else if (p2 == 7){
			for (int i = p1; i < 7; i++) {
				merged[index] = (arr1[i]);
				index++;
			}
			break;
		}
	}

	//Printout
	for (int i = 0; i < 14; i++) {
		cout << merged[i] << " ";
	}
}
