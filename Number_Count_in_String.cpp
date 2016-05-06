#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

	/*
	 * Find the number of occurrences of each number in a string
	 */

	//Generate random string
	string str = "Find the number of occurrences of each number in a string";
	srand(time(NULL));

	int add;
	for (int i = 0; i < str.length(); i++) {
		add = rand() % 100;
		if (add % 4 == 0) { //Randomly insert numbers based on a probability algorithm
			str.insert(i, to_string((add % 10)));
		}
	}
	cout << "String: \n" << str << endl;

}

