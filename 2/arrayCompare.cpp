#include "arrayCompare.h"

#define NULL 0

int sameElements(int *firstArray, int *secondArray, int size) {
	/* Temporary arrays are required, or else sorting the original
	arrays will permanently sort them as an unintentional side effect */
	int *tempFirstArray, *tempSecondArray;
	
	/* Allocate memory to the temporary arrays */
	tempFirstArray = new int[size];
	tempSecondArray = new int[size];
	
	/* Populate the temporary arrays with the values of the original
	arrays */
	for(int i = 0; i < size; ++i) {
		tempFirstArray[i] = firstArray[i];
		tempSecondArray[i] = secondArray[i];
	}
	
	/* Sort the temporary arrays */
	bubbleSort(tempFirstArray, size);
	bubbleSort(tempSecondArray, size);
	
	/* Compare each index from both arrays in turn */
	for(int i = 0; i < size; ++i)
		/* Return that it is false that the arrays have the same
		elements if an index does not yield the same element from both
		arrays */
		if(tempFirstArray[i] != tempSecondArray[i])
			/* Move to after temp array deletion */
			return 0;
	
	/* Delete the temporary arrays after the comparisons are over */
	delete[] tempFirstArray;
	delete[] tempSecondArray;
	
	/* If the above loop did not return, then the arrays must be
	identical when sorted, and thus have the exact same elements in the
	same quanitities */
	return 1;
}

int bubbleSort(int *array, int size) {
	int swap;
	
	if(array == NULL || size < 1)
		return 1;
	
	/* Carry out a full swap or bubble cycle for every pair of i and
	i + 1, which happens to be the size - 1.
	We count down from size - 1, so that we do not complete needless
	comparisons, hence why in the next loop we use i < j, where j is
	steadily decreasing. These needless comparisons arise from the fact
	that after the first bubble cycle, the very largest element is at
	the very top, and so the second largest on the second cycle, and so
	on. 
	This particular implementation was written from the inside at the if
	statement first, and backwards from there. */
	for(int j = size - 1; j > 1; --j) {
		/* Increment and repeat so that every pair of i and i + 1 get
		are compared */
		for(int i = 0; i < j; ++i) {
			/* Compare each element with the one above, swapping so that
			the greater of the two is above */
			if(array[i] > array[i + 1]) {
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
			}
		}
	}
	
	return 0;
}
