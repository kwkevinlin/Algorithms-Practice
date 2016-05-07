#include <iostream>
#include <algorithm>

using namespace std;

class minHeap {
private:
	int *arr;

public:

	minHeap(int val) {
		arr = new int[val];
	}
};

int main () {

	minHeap heap(5);
}
