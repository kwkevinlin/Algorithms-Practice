#include <iostream>

using namespace std;

int main() {

	/*
	 * Determine if there is an element in the array such that the
	 * sum of the elements on the left == sum of the elements on 
	 * the right.
	 *
	 * Example:
	 *     Input: 2        //Number of test cases
	 *            3        //Length of following case
	 *            1 2 3    //Test case
	 *            4
	 *            1 2 3 3
	 *     Output: NO
	 *             YES
	 *     Explanation:
	 *             Case 1: No such element
	 *             Case 2: [2], because (left) 1 + 2 == (right) 3
	 *
	 *
	 * Question adapted from:
	 *     HackerRank - Sherlock and Array
	 *     https://www.hackerrank.com/challenges/sherlock-and-array
	 *  
	 */

    int testCases, length, flag, sumL, sumR;
    
    cin >> testCases;
    
    for (int i = 0; i < testCases; i++) {
        cin >> length;
        
        //Temporary storing every element into array
        int storage[length];
        for (int j = 0; j < length; j++) {
            cin >> storage[j];    
        }
        
        //From second from first to second to last
        flag = 0;
        for (int j = 1; j < length - 1; j++) {
            for (int k = 0; k < length; k++) {
                if (k < j) {
                    sumL = sumL + storage[k];
                } else if (k > j) {
                    sumR = sumR + storage[k];
                }
            }
            if (sumL == sumR) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 1) {
            cout << "YES\n";
            flag = 0;
        } else {
            cout << "NO\n";
        }
    }

}
