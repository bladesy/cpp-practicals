#define NULL 0

/* Note that the array pointer is called by reference, as the pointer
value itself, the value that corresponds to a memory location, gets
overwritten to the memory location of the new array.
The arrayLength integer is also called by reference, as it must be
updated to keep up with the fact that the array has now increased by one
element. */
int insert(int *&array, int &arrayLength, int position, int value) {
	int *newArray, i;
	
	/* Exit the function with an error if the position is not within the
	bounds of the array, or if the array has not been specified */
	if(position < 0 || position > arrayLength || array == NULL)
		return -1;
	
	/* Assign memory to a new array, large enough to hold an additional
	element */
	newArray = new int[++arrayLength];
	
	/* Copy all values before the insertion to the new array */
	for(i = 0; i < position; ++i)
		newArray[i] = array[i];
	
	/* Insert the new value at the specified position */
	newArray[position] = value;
	
	/* Copy all values after the insertion to higher indexes */
	for(; i < arrayLength; ++i)
		newArray[i + 1] = array[i];
	
	/* Delete the original array */
	delete[] array;
	/* Point the original array pointer to the new array */
	array = newArray;
	
	return 0;
}

int remove(int *&array, int &arrayLength, int position) {
	int *newArray, i;
	
	/* Exit the function with an error if the position is not within the
	bounds of the array, or if the array has not been specified */
	if(position < 0 || position > arrayLength || array == NULL)
		return -1;
	
	/* Assign memory to a new array, which is smaller by one element */
	newArray = new int[--arrayLength];
	
	/* Copy all values before the removal to the new array */
	for(i = 0; i < position; ++i)
		newArray[i] = array[i];
	
	/* Copy all values after the specified position to lower indexes to
	effectively skip copying the element due for removal */
	for(; i < arrayLength; ++i)
		newArray[i - 1] = array[i];
	
	/* Delete the original array */
	delete[] array;
	/* Point the original array pointer to the new array */
	array = newArray;
	
	return 0;
}
