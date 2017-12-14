#include <iostream>
#include "Shape.h"

using namespace std;

void Shape::printData() {
	cout << "Area: " << area << " Perimeter: " << perimeter << endl;
}

void Rectangle::computeArea() {
	area = width * height;
}

void Rectangle::computePerimeter() {
	perimeter = 2 * width + 2 * height;
}

void Rectangle::readData() {
	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;
}

void Rectangle::printData() {
	cout << "Width: " << width << " Height: " << height << endl;
	cout << "Area: " << area << " Perimeter: " << perimeter << endl;
}
