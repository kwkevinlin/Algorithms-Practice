#include <iostream>
#include <fstream>

using namespace std;

int main() {

	/*
	 * Each file has the
following format: On the top line is the number of samples S followed by the number of features per
sample F. The rest of the file is S rows of F values, where each value is a real number between 0
and 1, with each value in the file separated by a space. As an example, an input data file with 4
samples of 2 features each would look like this:
	 *
	 *  kmeans K 			P 		  inputFile outputFile
	 *  	   numClusters  Processors
	 */

	//Run using 3 clusters

	int K = 3, samples, dimensions;
	float n;

	ifstream infile("kmeansSmall.txt");
	infile >> samples >> dimensions;

	float data[samples][dimensions];

	for (int i = 0; i < samples; i++) {
		infile >> n;
		data[i][0] = n;
		infile >> n;
		data[i][1] = n;
		cout << data[i][0] << ", " << data[i][1] << endl;
	}

}
