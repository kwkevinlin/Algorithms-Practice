#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(int X);

int main() {

	/*
	 *  Interview Question via HackerRank, notable company (re-worded):
	 * 	Given an integer, you are allowed to duplicate one of its individual
	 * 	number to its side. Find the largest variation of such. For example:
	 *
	 * Check: 13622				Check: 123456
	 * 	Variations:				 Variations:
	 * 		113622					 1123456
	 * 		133622					 1223456
	 * 		136622 (largest)		 1233456
	 * 		136222					 1234456
	 * 		136222					 1234556
	 *								 1234566 (largest)
	 */

	cout << solution(13622) << endl;
	cout << solution(123456);

}

int solution(int X) {

	string intX = to_string(X), ans1, ans2;

	for (int i = 1; i < intX.length(); i++) {
		if (intX[i-1] > intX[i]) {
			//substr(start element, length inclusive of start);
			ans1 = intX.substr(0, i) + string(1, intX[i-1]);
			ans2 = ans1 + intX.substr(i);
			return stoi(ans2);
		}
	}
	string ans = string(1, intX[intX.length()-1]);
	return stoi(intX.append(ans));
}
