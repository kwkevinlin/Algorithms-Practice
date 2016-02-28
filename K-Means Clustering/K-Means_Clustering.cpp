#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

	/*
	 *	Must run for arbitrary dimensions
	 *
	 *
	 *  ./kmeans K 			  P 		  inputFile outputFile
	 *  	     numClusters  Processors
	 *
	 *
	 *  	   1. Choose a number, k, which is how many clusters you expect the data to have.
	 *		   2. Make k guesses as to where those clusters could be. Your guesses will be wrong, but that doesn't matter.
	 *		   3. For each element in your data, assign it to the cluster it's closest to.
	 *		   4. Move the center of each cluster to be in the middle of the elements that are assigned to that cluster.
	 *		   5. Repeat steps 3 and 4 until no more data moves from one cluster to another.
	 *
	 *
	 *  Note: Arrays and loops are way too nested
	 *
	 *  Test inputs:
	 *  	K = 3, filename: kmeansSmall.txt
	 *  	K = 2, filename: testInputs1.txt
	 *
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
			cout << i << ": " << data[i][j] << " ";
		}
		cout << endl;
	}

	float clusters[K][samples][dimensions]; //K (3) clusters, with 12 slots each (max), and 2 coordinates per slot

	float kMeans[K][dimensions]; //Contains information about clusters[K] above. Ie. Clusters[] doesn't contain
								 //cluster coordinates

	//2. Make k guesses as to where those clusters could be. Your guesses will be wrong, but that doesn't matter.
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < dimensions; j++) {
			kMeans[i][j] = data[i][j]; //Populate initial cluster with first few samples (ie. cluster 1 = sample 1)
			cout << "Cluster " << i << ":" << j << " = " << kMeans[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//For step 3 below, declaring them above here
	float dist, minDist = 100000;
	int minCluster;
	int clusterIndex[K] = {0}; //Index to imitate stack in array
	//For step 4
	float storageDim[dimensions] = {0};

	/*==========================================================================
		Major loop starts here
	 */
	for (int z = 0; z < 5; z++) { //Repeat process for a max of 100 iterations

		//Quickly reset clusterIndex to overwrite data
		for (int r = 0; r < K; r++) { //Per cluster
			//memset(clusterIndex, 0, sizeof(clusterIndex));
			clusterIndex[r] = 0;
		}

		//3. For each element in your data, assign it to the cluster it's closest to.
		for (int i = 0; i < samples; i++) { //Per sample
			for (int j = 0; j < K; j++) { // Per cluster
				float calcKMeansBuffer = 0;
				for (int y = 0; y < dimensions; y++) { //Arbitrary dimensions

					/* Get distance to each cluster
					dX1 = kMeans[j][0];
					dX0 = data[i][0];
					dY1 = kMeans[j][1];
					dY0 = data[i][1];
					 */

					calcKMeansBuffer = calcKMeansBuffer + pow((kMeans[j][y] - data[i][y]), 2);
				}
				dist = sqrt(calcKMeansBuffer);

				if (dist < minDist) {
					minDist = dist;
					minCluster = j;
				}
			}
			cout << "Sample " << i << " closest cluster: " << minCluster << endl;
			minDist = 100000;
			//Add to closest cluster
			for (int y = 0; y < dimensions; y++) {
				clusters[minCluster][clusterIndex[minCluster]][y] = data[i][y];
				clusters[minCluster][clusterIndex[minCluster]][y] = data[i][y];
			}
			clusterIndex[minCluster]++;
		}

		for (int i = 0; i < K; i++) {
			cout << "Cluster " << i << " contains: " << clusterIndex[i] << " elements" << endl;
		}
		cout << endl;

		//4. Move the center of each cluster to be in the middle of the elements that are assigned to that cluster.
		//Get average of coordinates. x+x+x/n, y+y+y/n ? ###########################################################
		for (int i = 0; i < K; i++) { //Per Cluster
			cout << "Cluster " << i << " (avg): ";
			for (int j = 0; j < clusterIndex[i]; j++) { //For each sample in each cluster
				for (int y = 0; y < dimensions; y++) { //Per dimension

					storageDim[y] = storageDim[y] + clusters[i][j][y]; //Get all of dim, ex: x+x+x
				}
			}

			//After getting sum, divide by number of samples in the cluster
			for (int y = 0; y < dimensions; y++) { //Per dimension
				kMeans[i][y] = storageDim[y] / (float)clusterIndex[i]; //New average coordinates stored here
				cout << kMeans[i][y] << " ";
				storageDim[y] = 0;
			}
			cout << endl;
		}

		//5. Repeat. So move samples to closest clusters
		//Loop data[samples], compare to KMeans.


		cout << "//=========== Loop " << z + 1 << " ===========//\n";

	} //End 100 loop


}
