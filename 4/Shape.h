class Shape {
	public:
		/* Virtual Functions */
		/* These functions should be implemented by any inheriting
		classes */
		virtual void computeArea() = 0;
		virtual void computePerimeter() = 0;
		virtual void readData() = 0;
		virtual void printData();
	/* The protected access modifier ensures that inheriting classes can
	use the following declarations as though they were private */
	protected:
		double area, perimeter;
};

/* The Rectangle class inheirits the more general Shape class */
class Rectangle : public Shape {
	public:
		/* Overriding the virtual functions of Shape */
		void computeArea();
		void computePerimeter();
		void readData();
		void printData();
	private:
		int width, height;
};
