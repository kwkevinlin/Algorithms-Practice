#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

/* Uncomment to test random inputs */
//#include <cmath>
//#include <time.h>
//#include <cstdlib>

using namespace std;

int distributeCandy(vector<int>);

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	int res;

	int _score_size;
	cin >> _score_size;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _score;
	int _score_item;
	for(int _score_i=0; _score_i<_score_size; _score_i++) {
		cin >> _score_item;
		cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		_score.push_back(_score_item);
	}

	res = distributeCandy(_score);
	fout << res << endl;

	/*
	 * To test function with random input
	 */
	//	srand(time(NULL));
	//	vector<int> test;
	//	for (int i = 0; i < 5; i++) {
	//		test.push_back(rand() % 9 + 1);
	//		cout << test[i] << " ";
	//	}
	//	cout << endl;
	//	res = distributeCandy(test);

	// Result printout, uncomment to see output
	// cout << "\nTotal: " << res << endl;

	fout.close();
	return 0;
}


/*
 * Complete the function below.
 */
int distributeCandy(vector < int > score) {

	/*
        giving = number of candies distributed to the student
        totCandies = total number of candies giving out
	 */

	int prev = -1, giving = 0;
	int totCandies = 0;

	for (int i = 0; i < score.size(); i++) {
		cout << "Rating: " << score[i] << "\t\t";

		/* If first one, check to the right (iteratively) for number of consecutively decreasing elements
		 */
		if (i == 0) {
			giving = 1;

			if (score[i+1] < score[i]) { //If next one is smaller
				int count = 0;
				//Find number of consecutive smaller numbers
				for (int j = i + 1; j < score.size(); j++) {
					if (score[j] < score[j-1]) {
						count++;
					} else {
						break;
					}
				}

				giving = giving + count;
				totCandies = totCandies + giving;
				cout << "Candies: " << giving << ", total: " << totCandies;

			} else { //Just give one
				totCandies = totCandies + giving;
				cout << "Candies: " << giving << ", total: " << totCandies;
			}
		}

		/* If rating greater than previous, give prev + 1 candies to student
		 */
		else if (score[i] > prev) {
			giving++;
			totCandies = totCandies + giving;
			cout << "Candies: " << giving << ", total: " << totCandies;
		}

		/* Else, if rating is smaller
		 *     Check right to how many consecutive decreasing elements (conSecDecre) there are, then giving = conSecDecre + 1
		 * Else, if rating is equal to previous
		 *     Just give 1 candy
		 */
		else  {
			giving = 1;
			int count = 0;
			if (i + 1 < score.size()) { //If not last student
				if (score[i+1] < score[i]) { //If next one is smaller
					//Find number of consecutive smaller numbers
					for (int j = i + 1; j < score.size(); j++) {
						if (score[j] < score[j-1]) {
							count++;
						} else {
							break;
						}
					}

					giving = giving + count;
					totCandies = totCandies + giving;
					cout << "Candies: " << giving << ", total: " << totCandies;
				}
			}

			//If no consecutive decreasing elements found, just give 1 candy
			if (count == 0) {
				totCandies = totCandies + giving;
				cout << "Candies: " << giving << ", total: " << totCandies;
			}

		}
		prev = score[i];
		cout << endl;
	}


	return totCandies;
}

