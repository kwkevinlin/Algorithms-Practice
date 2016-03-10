#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	//Given a list of words, output buckets for set of words that are anagrams of each other.
	//For example, given the list of words {foo, ofo, bar} return two lists containing {foo, ofo} and {bar}

	string input[3] = {"foo", "ofo", "bar"};

	/*
	 * Second Approach: Sort each word, then compare.
	 * Sorted words == same, if they are anagrams (string has == function)
	 */

	int length = sizeof(input)/sizeof(input[0]);
	string words[length];

	//Sorting each word
	for (int i = 0; i < length; i++) {
		words[i] = input[i];
		sort(words[i].begin(), words[i].end());
	}

	//Test sorts
	for (int i = 0; i < length; i++) {
		cout << words[i] << endl;
	}

	//Categorizing to buckets
	unordered_map<string, list<string>> buckets;
	for (int i = 0; i < length; i++) {
		buckets[words[i]].push_back(input[i]);
	}

	//Printout Buckets to get Anagram groupings


//	for (auto itr = buckets.begin(); itr != buckets.end(); ++itr) {
//		for (int i = 0; i < itr->size(); i++) {
//			cout << itr[i] << endl;
//		}
//	}


}

