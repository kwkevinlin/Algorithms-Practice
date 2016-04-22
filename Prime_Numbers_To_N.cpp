#include <iostream>

using namespace std;

void findPrime(int);

int main() {


	/*
	 * Find all prime numbers to N
	 *
	 */

	bool isPrime = true;
	int i;
	for (i = 3; i < 30; i = i + 2) {
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

void findPrime(int) {



}
