#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	//Given a list of words, output buckets for set of words that are anagrams of each other.
	//For example, given the list of words {foo, ofo, bar} return two lists containing {foo, ofo} and {bar}

	list<string> input;
	input.push_back("foo");
	input.push_back("ofo");
	input.push_back("bar");

	/*
	 * Second Approach: Sort each word, then compare.
	 * Sorted words == same, if they are anagrams (string has == function)
	 */

	string words[input.size()];

	//Sorting each word
	int i = 0;
	while (input.empty() != 1) {
		words[i] = input.front();
		sort(words[i].begin(), words[i].end());
		input.pop_front();
		i++;
	}

	//Test sort
	for (i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
		cout << words[i];
	}


}

