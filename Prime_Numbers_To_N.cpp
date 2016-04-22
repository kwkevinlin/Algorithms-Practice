#include <iostream>

using namespace std;

void findPrime(int);

int main() {


	/*
	 * Write a function to find all prime numbers until N
	 *
	 * Primitive solution of O(N^2) time
	 */

	int findPrimeUntil = 50;

	findPrime(findPrimeUntil);

}

void findPrime(int N) {

	bool isPrime = true;
	int i;
	for (i = 3; i < N; i = i + 2) {
		for (int j = 3; j < i; j++) {

			if (i % j == 0) {
				//Not a prime
				isPrime = false;
				break;
			}
		}
		if (isPrime == true) {
			cout << i << endl;
		} else {
			isPrime = true;
		}
	}
}
