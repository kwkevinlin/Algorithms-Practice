#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

	/*
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


	//Running using 3 clusters right now

	int K = 3, samples, dimensions;
	float n;

	ifstream infile("kmeansSmall.txt");
	infile >> samples >> dimensions;

	float data[samples][dimensions];

	//Reading in coordinates to 2D array
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

	//2. Make k guesses as to where those clusters could be. Your guesses will be wrong, but that doesn't matter.
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < dimensions; j++) {
			kMeans[i][j] = data[i][j]; //Populate initial cluster with first few samples (ie. cluster 1 = sample 1)
			cout << "Cluster " << i << ":" << j << " = " << kMeans[i][j] << " ";
		}
		cout << endl;
	}

	//3. For each element in your data, assign it to the cluster it's closest to.
	float dist, minDist = 100000;
	int minCluster;
	for (int i = 0; i < samples; i++) { //Per sample
		for (int j = 0; j < K; j++) { // Per cluster
			//for (int y = 0; y < dimensions; y++) { //Arbitrary dimensions

			/* PRETEND ONLY 2 DIMENSIONS POSSIBLE */

			/* Get distance to each cluster
				dX1 = kMeans[j][0];
				dX0 = data[i][0];
				dY1 = kMeans[j][1];
				dY0 = data[i][1];
			 */
			//cout << "\nSample " << i << "->Cluster " << j;
			dist = sqrt(pow((kMeans[j][0] - data[i][0]), 2) + pow((kMeans[j][1] - data[i][1]), 2));
			//cout << "= Dist: " << dist;

			if (dist < minDist) {
				minDist = dist;
				minCluster = j;
			}
			//}
		}
		cout << "\nSample " << i << " closest cluster: " << minCluster << endl;
		minDist = 100000;

	}

	//4. Move the center of each cluster to be in the middle of the elements that are assigned to that cluster.





}
