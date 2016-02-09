#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	/*
	 * "There's a simple problem people like to give to applicants for a coding job called fizz-buzz and
	 * apparently it weeds out 99% of applicants. It goes something like this:
	 *
	 * Write a program that will count and print numbers to 100 and for every multiple of 3 will write 'fizz'
	 * and for every multiple of 5 will write 'buzz' and for every multiple of 3 and 5 will write 'fizzbuzz'"
	 */

	for (int i = 0; i < 101; i++) {

		//If starting from i = 0, skip 0 because 0 is not divisible by 3 or 5
		if (i == 0)
			continue;

		if (i % 3 == 0 && i % 5 == 0)
			cout << "fizzbuzz, i = " << i << "\n";
		else if(i % 3 == 0)
			cout << "fizz, i = " << i << "\n";
		else if (i % 5 == 0)
			cout << "buzz, i = " << i << "\n";
	}
}
