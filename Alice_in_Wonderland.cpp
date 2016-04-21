#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool comparePair(pair<string, int>, pair<string, int>);

int main() {

	/*
	 * Given the book: Alice in Wonderland, print out the top 10
	 * words with the most amount of occurences.
	 *
	 * The txt version of the novel can be downloaded from:
	 * http://www.umich.edu/~umfandsf/other/ebooks/alice30.txt
	 *
	 * Solution:
	 *     Parse the input, and store it into a hash. Then, convert
	 *     hash to vector<pairs>, the use std::sort() with self-
	 *     defined predicate function to sort the vector of pairs.
	 *     Print out the last 10 indexes to get the 10 most seen
	 *     word.
	 */

	ifstream book("alice-in-wonderland.txt");
	if (book.fail()) {
		exit(-1);
	}

	unordered_map<string, int> histogram;

	char in, peek;
	stringstream ss;

	while (book >> in) {

		//ASCII Table
		//Upper case: 65 - 90
		//Lower case: 97 - 122

		if (in >= 65 && in <= 90 || in >= 97 && in <= 122) { //Is a word
			ss << in;
		}

		//Next char is space or newline
		peek = book.peek();
		if (peek == ' ' || peek == '\n') {
			histogram[ss.str()]++; //Convert stringstream back to string, then insert into map
			ss.str("");
			continue;
		}

	}

	vector<pair<string, int>> vecHisto;

	//Store into vector
	for (auto kv : histogram) {
		//cout << kv.first << " : " << kv.second << endl;
		vecHisto.push_back(make_pair(kv.first, kv.second));
	}

	//Sort vector
	sort(vecHisto.begin(), vecHisto.end(), comparePair);

	//Print last 10
	for (int i = vecHisto.size() - 1; i >= vecHisto.size() - 10; i--) {
		cout << vecHisto[i].first << " : " << vecHisto[i].second << endl;
	}

}

bool comparePair(pair<string, int> p1, pair<string, int> p2) {
	return p1.second < p2.second;
}
