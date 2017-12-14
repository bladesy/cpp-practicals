#include <iostream>
#include "VecSim.h"

using namespace std;

int main(void) {
	double vector1[10] 
		= {1.5, 3., 4.5, 6., 7.5, 9., 10.5, 12., 13.5, 15.},
	vector2[10] 
		= {3., 4.5, 6., 7.5, 9., 10.5, 12., 13.5, 15., 16.5};
	VecSim myVecSim;
	
	cout << "Euclidean: "
		<< myVecSim.euclideanDistance(vector1, vector2, 10) << endl;
	cout << "Cosine: "
		<< myVecSim.cosineSimilarity(vector1, vector2, 10) << endl;
	
	return 0;
}
