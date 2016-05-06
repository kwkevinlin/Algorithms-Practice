#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <map>

using namespace std;

string populateStr(string);
map<int, int> createHistogram(string);

int main() {

	/*
	 * Find the number of occurrences of each number in a string
	 */

	//Generate random string
	string str = "Find the number of occurrences of each number in a string";
	srand(time(NULL));

	//Insert numbers into string
	str = populateStr(str);

	//Produce histogram of numbers
	map<int, int> histogram = createHistogram(str);

	//Histogram printout
	cout << "\nHistogram of each number:\n";
	for (auto kv : histogram) {
		cout << kv.first - '0' << ": " << kv.second << endl;
	}
}

string populateStr(string str) {
	int dice;
	for (int i = 0; i < str.length(); i++) {
		dice = rand() % 9;
		if (dice % 6 == 0) { //Randomly insert numbers based on a probability algorithm
			str.insert(i, to_string((rand() % 10)));
		}
	}
	cout << "Input: \n" << str << endl;
	return str;
}

map<int, int> createHistogram(string str) {

	map<int, int> histogram;

	//Pre-populate histogram (0-9)
	for (int i = 0; i < 10; i++) {
		histogram[i];
	}

	//Populate histogram for above numbers
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') { //ASCII check to see if str[i] is a number
			histogram[str[i] - '0']++;
		}
	}

	return histogram;
}
