//Question 3

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool parseInputs(string, map<char, vector<char>>&, map<char, int>&, char&);
void lexiSExpressionPrint(map<char, vector<char>>, char);

int main() {
    
    string input;
    getline(cin, input);
    
    char root;
    map<char, vector<char>> adjList; //Adjacency list of every parent to every child
    map<char, int> numParents; //Map of all nodes to number of parents. Used for E4, E5 checks.
    
    //Parse inputs and perform error checking
    if (!parseInputs(input, adjList, numParents, root)) { //parseInputs returns false if error was found
        return 0; 
    }
    
    //If no errors found, printout lexicographically smallest S-Expression
    lexiSExpressionPrint(adjList, root);    

    return 0;
}

bool parseInputs(string input, map<char, vector<char>>& adjList, map<char, int>& numParents, char& root) {
    
    char parent;
    int index = 0;
    bool E5Error = false;
    
    //For every char in input string
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != '(' && input[i] != ')' && input[i] != ',' && input[i] != ' ') { //If input[i] is a node
            index++;
            if (index % 2 == 1) { //input[i] is a parent node. Store it for use in next iteration.
                
                //Input format check (E1)
                if (i - 1 >= 0 && input[i-1] != '(') {
                    cout << "E1\n";
                    return false;
                } else if (i + 1 < input.length() && input[i+1] != ',') {
                    cout << "E1\n";
                    return false;
                } 
                
                //Store parent for use in next iteration
                parent = input[i];
                
            } else { //input[i] is a child node. Check for input errors, then add to adjacency list if error checks pass
                
                //Input format check (E1)
                if (i - 1 >= 0 && input[i-1] != ',') {
                    cout << "E1\n";
                    return false;
                } else if (i + 1 < input.length() && input[i+1] != ')') {
                    cout << "E1\n";
                    return false;
                } 
                
                //Duplicates check (E2)
                for (int j = 0; j < adjList[parent].size(); j++) { //Opportunity for time complexity improvements here
                    if (adjList[parent][j] == input[i]) { //If there is already such a parent/child pair
                        cout << "E2\n";
                        return false;
                    }
                } 
                //Binary tree violations check (E3)
                if (adjList[parent].size() == 2) { //If parent node already has 2 child
                    cout << "E3\n";
                    return false;
                }
                
                //Multiple parents (tree contains cycle) check (E5)
                numParents[input[i]]++;
                numParents[parent];
                if (numParents[input[i]] == 2) { //If node has 2 parents already
                    E5Error = true;
                }
                
                //Else (no violations), store to adjacency list
                adjList[parent].push_back(input[i]);
                index = 0;
            }
        } else if (i - 1 <= 0 && input[i] == ' ') { //If input[i] is not a tree node, then perform input format check for consecutive spaces (E1)
            if (input[i] == ' ') {
                cout << "E1\n";
                return false;
            }
        }
    }
    
    //Multiple roots check (E4)
    int numRoots = 0;
    for (auto kv : numParents) {
        if (kv.second == 0) { //If node has no parents, it has to be a root
            root = kv.first; //Set root of tree for S-Expression printout later
            numRoots++;
            if (numRoots == 2) { //If tree has more than 1 root
                cout << "E4\n";
                return false;
            }
        }
    }
    
    //Cycle check (E5) printout. This section has to be performed after E4's check to print errors in order (E5)
    if (E5Error == true) {
        cout << "E5\n";
        return false;
    }
    
    //No errors
    return true;
}

void lexiSExpressionPrint(map<char, vector<char>> adjList, char current) {
   
    cout << "(" << current;
    int numChild = adjList[current].size();
    if (numChild == 1) {
        lexiSExpressionPrint(adjList, adjList[current][0]);
    } else if (numChild == 2) { 
        //Determine lexicographically smallest ordering
        if (adjList[current][0] < adjList[current][1]) { 
            lexiSExpressionPrint(adjList, adjList[current][0]);
            lexiSExpressionPrint(adjList, adjList[current][1]);
        } else {
            lexiSExpressionPrint(adjList, adjList[current][1]);
            lexiSExpressionPrint(adjList, adjList[current][0]);
        }
    }
    cout << ")";

}