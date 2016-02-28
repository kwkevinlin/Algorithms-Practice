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
	 *	Must run for arbitrary dimensions
	 *
	 *
	 *  kmeans K 			P 		  inputFile outputFile
	 *  	   numClusters  Processors
	 *
	 *
	 *  	   1. Choose a number, k, which is how many clusters you expect the data to have.
			   2. Make k guesses as to where those clusters could be. Your guesses will be wrong, but that doesn't matter.
			   3. For each element in your data, assign it to the cluster it's closest to.
			   4. Move the center of each cluster to be in the middle of the elements that are assigned to that cluster.
			   5. Repeat steps 3 and 4 until no more data moves from one cluster to another.


	 */

	//Run using 3 clusters

	int K = 3, samples, dimensions;
	float n;

	ifstream infile("kmeansSmall.txt");
	infile >> samples >> dimensions;

	float data[samples][dimensions];

	for (int i = 0; i < samples; i++) {
		for (int j = 0; j < dimensions; j++) {
			infile >> n;
			data[i][j] = n;
			cout << data[i][j] << " ";
		}
		cout << endl;
	}

	float clusters[K][samples][dimensions]; //K (3) clusters, with 12 slots each (max), and 2 coordinates per slot

	float kMeans[K][dimensions];

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < dimensions; j++) {
			kMeans[i][j] = data[i][j]; //Populate initial cluster with first few samples (ie. cluster 1 = sample 1)
			cout << "Cluster " << i << ":" << j << " = " << kMeans[i][j] << " ";
		}
		cout << endl;
	}




}
