#ifndef VECSIM
#define VECSIM

/* Measures the similarity of two 1D vectors */
class VecSim {
	public:
		/* Constructors */
		VecSim();
		VecSim(double *firstVector, double *secondVector, int len);
		
		/* Alternate, inline constructor */
		/* 
		VecSim(double *firstVector, double *secondVector, int len) : 
			firstVector(firstVector), secondVector(secondVector), 
			len(len) {}; 
		*/
		
		double euclideanDistance();
		double euclideanDistance(double *firstVector, 
			double *secondVector, int len);
		
		double cosineSimilarity();
		double cosineSimilarity(double *firstVector, 
			double *secondVector, int len);
	private:
		double *firstVector, *secondVector;
		int len;
		double innerProduct(double *firstVector, double *secondVector, 
			int len);
};

#endif
