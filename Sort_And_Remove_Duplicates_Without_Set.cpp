#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	/*
	 * Sort and remove duplicates in an array without using set
	 */

	int num[10] = {8, 1, 4, 9, 0, 4, 9, 9, 3, 5};

	sort(num, num + 10);

	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}

	int offset = 0;
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
	cout << "\n" << offset << "\n";

	for (int i = 0; i < 10 - offset; i++) { //Don't display duplicates
		cout << num[i] << " ";
	}

}
