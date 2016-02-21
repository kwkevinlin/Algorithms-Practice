#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Problem:
        You are given NN integers.Then you are given 22 queries.First query consists of 11 integer denoting the position which should be removed.Next query consists of 22 integers denoting the range that should be removed.

    Input Format:
        The first line of the input contains an integer NN.The next line contains NN space separated integers.The third line contains a single integer xx,denoting the position of an element that should be removed from the vector.The fourth line contains two integers aa and bb denoting the range that should be erased from the vector inclusive of a and exclusive of b.
        
    Output Format:
        Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space.

    Sample Input:
        6
        1 4 6 2 8 9
        2
        2 4

    Sample Output:
        3
        1 8 9
        
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size, n, n2;
    cin >> size;
    
    vector<int> vec;
    for (int i = 0; i < size; i++) {
        cin >> n;
        vec.push_back(n);
    }
    
    cin >> n;
    vec.erase(vec.begin() + n - 1); // n is the nth position, so n-1 to get [pos]
    
    cin >> n >> n2;
    vec.erase(vec.begin() + n - 1, vec.begin() + n2 - 1);
    
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    
    return 0;
}
