#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include "etime.h"

/*
	Parallel K-Means Clustering using PThreads and arbitrary dimensions

	To Do:
		Optimize for loops to minimize complexity

 */

long thread_count;
int K, samples, dimensions, flag = 1, flagEx = 1;

pthread_mutex_t mutex;
pthread_barrier_t barrier;
int *dataClusterIndex; //Creating dataClusterIndex to map samples to corresponding cluster
int *prevDataCluster; //Secondary dataClusterIndex to check when to end 100x loop
int *clusterElements; //Number of samples in each cluster
int *randomCheck; //Making sure no duplicate initial cluster coordinates are generated
double **data; //Creating data[samples][dimensions] array to store samples its coordinates
double **clusterInfo; //Creating clusterInfo to store coordinates of each cluster


void *kMeans (void* rank);

int main(int argc, char* argv[]) {


	FILE *inputFile, *outputFile;

	if (argc != 5) {
		printf("Incorrect parameters.\n");
		exit(-1);
	} else {
		K = strtol(argv[1], NULL, 10);
		thread_count = strtol(argv[2], NULL, 10);
		inputFile = fopen(argv[3], "r");
		outputFile = fopen(argv[4], "w+");
	}

	//Reading in data to dynamic array
	fscanf(inputFile, "%i", &samples);
	fscanf(inputFile, "%i", &dimensions);

	//printf("Clusters: %i, Processors: %ld\n", K, thread_count);
	//printf("Samples: %i, Dimensions: %i\n", samples, dimensions);

	//For all loops
	int i, j;

	//Initializing all globals
	dataClusterIndex = (int *)malloc(samples * sizeof(int));
	prevDataCluster = (int *)malloc(samples * sizeof(int));
	clusterElements = (int *)malloc(K * sizeof(int));
	randomCheck = (int *)malloc(samples * sizeof(int));
	data = (double **)malloc(samples * sizeof(double *));
	clusterInfo = (double **)malloc(K * sizeof(double *));

	//Continue allocating 2nd dimensions to data[samples][dimensions]
	for (i = 0; i < samples; i++) {
		data[i] = (double *)malloc(dimensions * sizeof(double));
		prevDataCluster[i] = 0;
	}

	//Reading in coordinates to array of arbitrary dimension
	double buffer;
	for (i = 0; i < samples; i++) {
		randomCheck[i] = 0;
		for (j = 0; j < dimensions; j++) {
			fscanf(inputFile, "%lf", &buffer);
			data[i][j] = buffer;
		}
	}

	//Continue allocating 2nd dimension to clusterInfo[K][dimensions]
	for (i = 0; i < K; i++)
		clusterInfo[i] = (double *)malloc(dimensions * sizeof(double));

	//2. Seting initial cluster coordinates as coordinates
	srand(time(NULL));
	for (i = 0; i < K; i++) {
		int randData = rand() % samples;
		while(randomCheck[randData] == 1) {
			randData = rand() % samples;
		}
		randomCheck[randData] = 1;

		for (j = 0; j < dimensions; j++) {
			clusterInfo[i][j] = data[randData][j];
			//clusterInfo[i][j] = data[i][j]; //Populate initial cluster with first K samples (ie. cluster 1 = sample 1)
			//printf("Cluster %i:%i = %lf ", i, j, clusterInfo[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");

	//PThreads setup
	long       thread;  /* Use long in case of a 64-bit system */
	pthread_t* thread_handles;
	thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t));
	pthread_mutex_init(&mutex, NULL); //For mutex
	pthread_barrier_init(&barrier, NULL, thread_count); //For barrier synchronization

	tic();

	//Creating, distributing, calling, and joining pthread workers
	//==============================================================

	for (thread = 0; thread < thread_count; thread++)
		pthread_create(&thread_handles[thread], NULL, kMeans, (void*)thread);


	for (thread = 0; thread < thread_count; thread++)
		pthread_join(thread_handles[thread], NULL);

	//==============================================================

	toc();

	//Output results to 'argv[4]'.txt
	fprintf(outputFile, "%i\n", samples);
	for (i = 0; i < samples; i++) {
		fprintf(outputFile, "%i\n", dataClusterIndex[i]);
	}

	//printf("Completed!\nTime: %lf\n", etime());
	printf("%lf\n", etime());

	return 0;

}

void *kMeans(void* rank) {
	long my_rank = (long) rank;
	long chunk_size, start, end;
	int i, j, y, z;
	double dist, calcKMeansBuffer, minDist = 1000000;

	/* If less threads than samples, attempt to distribute evenly
	 * Else, if number of threads more than number of samples,
	 * assign linearly until all samples have one thread
	 */
	if (thread_count < samples) {
		chunk_size = samples / thread_count; //N
		start = my_rank * chunk_size;
		end = (my_rank + 1) * chunk_size - 1;

		//Last one deals with the rest
		if (my_rank == (thread_count - 1))
			end = samples - 1;
	} else {
		if (my_rank <= samples - 1) {
			start = my_rank;
			end = my_rank;
		} else {
			start = 0;
			end = -1; //Will never pass for loops
		}
	}
	//printf("Rank: %li, start: %li, end: %li\n", my_rank, start, end);


	/*==========================================================================
		Major loop starts here
	 */
	for (z = 0; z < 100; z++) { //Repeat process for a maximum of 100 iterations

		//Resetting clusterElement for each loop
		if (my_rank == 0) {
			for (i = 0; i < K; i++) {
				clusterElements[i] = 0;
			}
		}

		//Barrier 1
		int rc = pthread_barrier_wait(&barrier);
		if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
		{
			printf("Barrier error\n");
			exit(-1);
		}

		//3. For each element in your data, assign it to the cluster it's closest to.
		for (i = start; i <= end; i++) { //Per assigned samples (ie, 2 samples)

			for (j = 0; j < K; j++) { // Per cluster

				calcKMeansBuffer = 0;
				for (y = 0; y < dimensions; y++) { //Arbitrary dimensions

					calcKMeansBuffer = calcKMeansBuffer + pow((clusterInfo[j][y] - data[i][y]), 2);

				}
				dist = sqrt(calcKMeansBuffer);

				if (dist < minDist) {
					minDist = dist;
					dataClusterIndex[i] = j;
				}

			}
			//To stop loop if no samples relocate clusters anymore
			//If even one changed, then continue looping
			if (dataClusterIndex[i] != prevDataCluster[i]) {
				flag = 0;
			}

			//Update prev for next iteration
			prevDataCluster[i] = dataClusterIndex[i];

			//printf("Sample %i closest cluster: %i\n", i, dataClusterIndex[i]);

			//Update number of elements in each cluster
			pthread_mutex_lock(&mutex);
			clusterElements[dataClusterIndex[i]]++;
			pthread_mutex_unlock(&mutex);

			minDist = 1000000;

		}

		//Barrier 2
		rc = pthread_barrier_wait(&barrier);
		if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
		{
			printf("Barrier error\n");
			exit(-1);
		}

		if (my_rank == 0) { //Only 1 thread needs to run this
			for (i = 0; i < K; i++) {
				//printf("Cluster %i contains: %i elements\n", i, clusterElements[i]); //Uncomment for tracing
				for (j = 0; j < dimensions; j++) {
					//printf("clusterInfo: %lf\n", clusterInfo[i][j]);
					clusterInfo[i][j] = 0;
				}
			}
		}

		//Barrier 3
		rc = pthread_barrier_wait(&barrier);
		if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
		{
			printf("Barrier error\n");
			exit(-1);
		}


		//4. Move the center of each cluster to be the average of existing samples associated with itself
		for (j = start; j <= end; j++) { //For samples in the thread, in each cluster

			pthread_mutex_lock(&mutex);

			for (y = 0; y < dimensions; y++) { //Per dimension
				clusterInfo[dataClusterIndex[j]][y] = clusterInfo[dataClusterIndex[j]][y] + data[j][y];
			}

			//took out mutex
			pthread_mutex_unlock(&mutex);

		}

		//Barrier 4
		rc = pthread_barrier_wait(&barrier);
		if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
		{
			printf("Barrier error\n");
			exit(-1);
		}

		//After getting sum, divide by number of samples in the cluster
		if (my_rank == 0) {
			for (i = 0; i < K; i++) { //Per Cluster
				//printf("Cluster %i: ", i); //Uncomment for tracing
				for (y = 0; y < dimensions; y++) {

					if (clusterInfo[i][y] != 0) { //Since clusters are randomly assigned, there is a potential for empty clusters
						clusterInfo[i][y] = clusterInfo[i][y] / (double) clusterElements[i];
					}
					//printf("%lf ", clusterInfo[i][y]); //Uncomment for tracing

				}
				//printf("\n"); //Uncomment for tracing
			}


		}

		if (my_rank == 0) {
			//printf("//=========== Loop %i ===========//\n", z + 1); //Uncomment for tracing
		}

		//Determining when to stop 100 loop iteration, continues after barrier
		pthread_mutex_lock(&mutex);
		flagEx = (flagEx & flag); //Have to check each thread to see if all no change (ie. all stay 1)
		pthread_mutex_unlock(&mutex);

		//Barrier 5
		rc = pthread_barrier_wait(&barrier);
		if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
		{
			printf("Barrier error\n");
			exit(-1);
		}

		//If no samples relocate, kmeans clustering is done
		if (flagEx == 1) { //So no flag in all threads == 0
			break;
		}

		//Barrier 6
		rc = pthread_barrier_wait(&barrier);
		if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
		{
			printf("Barrier error\n");
			exit(-1);
		}

		flag = 1;
		flagEx = 1;


	} //End major loop

	return NULL;

}
