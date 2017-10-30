#ifndef ALTER_ARRAY
#define ALTER_ARRAY

/* Insert a value at a certain position of the array, maintaining all
other values already in the array, by pushing the value at the specified
position forward */
int insert(int *&array, int &arrayLength, int position, int value);

/* Remove a value from the array at a certain position, decreasing the
number of elements in the array and pushing all proceeding values
backwards */
int remove(int *&array, int &arrayLength, int position);

#endif
