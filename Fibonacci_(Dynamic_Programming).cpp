#include <iostream>

using namespace std;

int fibDP(int);

int main() {

	/*
	 * Fibonacci via Dynamic Programming
	 *     Time: O(n), linear
	 *     Space: O(n)
	 */

	int find = 10;

	cout << fibDP(find) << endl;

}

int fibDP(int find) {

	if (find == 1) {
		return 1;
	} else if (find == 0) {
		return 0;
	}

	//Each index contains fib of that index number. Ex: find = 5, need [0..5] so [find+1]
	int fib[find+1];
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= find; i++) {
		//Since [0] and [1] already filled, calculate up until [find]
		fib[i] = fib[i-1] + fib[i-2];
	}

	return fib[find];

}

