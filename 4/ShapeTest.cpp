#include <iostream>
#include "Shape.h"

using namespace std;

int main(void) {
	Rectangle rectangle;
	Shape *shapePointer = &rectangle;
	
	/* Taking rectangle as a Rectangle */
	rectangle.readData();
	rectangle.computeArea();
	rectangle.computePerimeter();
	rectangle.printData();
	
	/* Taking rectangle as a Shape */
	shapePointer->printData();
	shapePointer->readData();
	shapePointer->computeArea();
	shapePointer->computePerimeter();
	shapePointer->printData();
	
	return 0;
}
