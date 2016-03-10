#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


int main() {

	//Given a list of words, output buckets for set of words that are anagrams of each other.
	//For example, given the list of words {foo, ofo, bar} return two lists containing {foo, ofo} and {bar}

	list<string> words;
	words.push_back("foo");
	words.push_back("ofo");
	words.push_back("bar");

	/*
	 * Simple Approach First: Create hash for each word.
	 * For each word, traverse through other hashes to check if is anagram
	*/
	int i = 0;
	unordered_map<char, int> hashArray[words.size()];
	while (words.empty() == 0) {
		string word = words.front();
		for (int j = 0; j < word.length(); j++) {
			hashArray[i][word[j]]++; //Storing chars into appropriate hash
		}
		words.pop_front();
		i++;
	}



}

