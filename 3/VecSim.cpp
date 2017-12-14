#include <cmath>
#include "VecSim.h"

using namespace std;

VecSim::VecSim() {
}

VecSim::VecSim(double *firstVector, double *secondVector, int len) {
	this->firstVector = firstVector;
	this->secondVector = secondVector;
	this->len = len;
}

double VecSim::euclideanDistance() {
	euclideanDistance(firstVector, secondVector, len);
}

double VecSim::euclideanDistance(double *firstVector, 
	double *secondVector, int len) {
	double sum = 0;
	for(int i = 0; i < len; ++i)
		sum += pow(firstVector[i], 2) 
			- (2 * firstVector[i] * secondVector[i])
			+ pow(secondVector[i], 2);
	return sqrt(sum);
}

double VecSim::cosineSimilarity() {
	cosineSimilarity(firstVector, secondVector, len);
}

double VecSim::cosineSimilarity(double *firstVector, 
	double *secondVector, int len) {
	double firstSum = 0, secondSum = 0;
	for(int i = 0; i < len; ++i) {
		firstSum += pow(firstVector[i], 2);
		secondSum += pow(secondVector[i], 2);
	}
	return innerProduct(firstVector, secondVector, len) 
		/ (sqrt(firstSum) * sqrt(secondSum));
}

double VecSim::innerProduct(double *firstVector, double *secondVector, 
	int len) {
	double sum = 0;
	for(int i = 0; i < len; ++i)
		sum += firstVector[i] * secondVector[i];
	return sum;
}
