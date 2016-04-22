#include <iostream>

using namespace std;

void findPrime(int);

int main() {


	/*
	 * Write a function to find all prime numbers until N
	 *
	 * Primitive solution of O(N^2) time, with a few looping
	 * tricks to achieve not fully O(N^2)
	 */

	int findPrimeUntil = 50;

	findPrime(findPrimeUntil);

}

void findPrime(int N) {

	cout << 2 << endl; //2 is the first prime number

	bool isPrime = true;
	for (int i = 3; i < N; i += 2) { //Dont need to count evens
		for (int j = 3; j < i; j += 2) { //Don't need to check evens either

			if (i % j == 0) {
				//Not a prime
				isPrime = false;
				break;
			}
		}
		if (isPrime == true) {
			//Is a prime
			cout << i << endl;
		} else {
			isPrime = true;
		}
	}
}
