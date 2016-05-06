#include <iostream>
#include <algorithm>

using namespace std;

void print(int[], int);
void removeDuplicates(int[], int, int&);

int main() {

	/*
	 * Sort and remove duplicates in an array without using set
	 *
	 * Complexity: n log n for std::sort
	 */

	//Create test array
	int num[10] = {8, 1, 4, 9, 0, 4, 9, 9, 3, 5};

	//std::sort
	sort(num, num + 10);

	//Printout
	print(num, 10);

	//Offset = number of extra duplicate elements
	int offset = 0;

	//Remove duplicates
	removeDuplicates(num, 10, offset);

	//Printout
	print(num, 10 - offset); //Don't display duplicates

}

void print(int num[], int size) {
	for (int i = 0; i < size; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
}

void removeDuplicates(int num[], int size, int& offset) {
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (num[j] != num[i]) {
				break;
			} else {
				i = j;
				offset++;
			}
		}
		num[i] = num[i + offset];
	}
}
