#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

	/*
	 * Find the number of occurrences of each number in a string
	 */

	//Generate random string
	stringstream ss("find the number of occurrences of each number in a string");
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		ss << rand() % 10;
	}

	cout << ss.str();

}

