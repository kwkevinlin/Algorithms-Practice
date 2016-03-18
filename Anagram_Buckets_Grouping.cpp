#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	/* Given a list of words, output buckets for set of words that are anagrams of each other.
	 * For example, given the list of words {foo, ofo, bar} return two lists containing {foo, ofo} and {bar}
	 *
	 * Approach:
	 * 		Sort each word, then assign them into an unordered_map<string, list<string>>
	 * 		Since sorted word == anagram, they will be chained to the same list when
	 * 		hashed.
	 * 		Output lists in buckets to get anagram groupin.
	 */

	//Test inputs here
	string input[] = {"foo", "ofo", "bar"};

	int length = sizeof(input)/sizeof(input[0]);
	string words[length];

	//Sorting each word
	for (int i = 0; i < length; i++) {
		words[i] = input[i];
		sort(words[i].begin(), words[i].end());
	}

	//Categorizing to buckets
	unordered_map<string, list<string>> buckets;
	for (int i = 0; i < length; i++) {
		buckets[words[i]].push_back(input[i]);
	}

	//Printout Buckets to get anagram groupings
	int i = 1;
	for(auto kv : buckets) {
		cout << "Bucket " << i << ": ";
		while (kv.second.size() != 0) {
			cout << kv.second.front() << " ";
			kv.second.pop_front();
		}
		i++;
		cout << endl;
	}

}
