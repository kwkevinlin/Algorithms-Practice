#include <iostream>

using namespace std;

int fibDP(int);

int main() {

	/*
	 * Fibonacci via Dynamic Programming
	 */

	int find = 5;

	cout << fibDP(find) << endl;

}

int fibDP(int find) {

	if (find == 1) {
		return 1;
	} else if (find == 0) {
		return 0;
	}

	
	
}

