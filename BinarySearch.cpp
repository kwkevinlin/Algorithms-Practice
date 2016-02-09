#include <iostream>

using namespace std;

int binary_search(int[], int, int, int);

int main () {

	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	//Change this to find values
	int findThis = 5;

	int index = binary_search(arr, 0, sizeof(arr)/sizeof(arr[0]) -1, findThis);

	if (index == -1)
		cout << "\nValue not found.\n";
	else
		cout << "\nFound: " << findThis << " at " << arr[index] << endl;
}

int binary_search(int arr[], int begin, int end, int findThis) {

	if (begin > end)
		return -1;

	int mid = (end + begin) / 2;

	cout << "Mid: " << mid << ", Begin: " << begin << ", End: " << end << endl;

	if (arr[mid] == findThis)
		return mid;
	else if (arr[mid] > findThis) {
		cout << "<-\n";
		binary_search(arr, begin, mid - 1, findThis);
	} else { //arr[mid] < findThis
		cout << "->\n";
		binary_search(arr, mid + 1, end, findThis);
	}

}