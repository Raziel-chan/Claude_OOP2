// Claude_OOP_exercice2.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Exercise: Shape Hierarchy
*/
#define _USE_MATH_DEFINES
using namespace std;
#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>

class Shape {
public:
    string shapeName = "";
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
    Shape() : shapeName("") {}
    Shape(string name) : shapeName(name){}
};
// Implement Circle and Rectangle classes here
class Circle : public Shape {
private:
    const double radius;
public:
    Circle(double r) : radius(r), Shape("Circle") {}

    double area() const {
    	return M_PI * (radius * radius);
    }

    double perimeter() const {
		return 2 * M_PI * radius;
	}
    ~Circle() {}
};

class Rectangle : public Shape {
    private:
	   const double length;
	   const double width;
    public:
        Rectangle(double l, double w) : length(l), width(w), Shape("Rectangle") {}
        double area() const {
			return length * width;
		}
        double perimeter() const {
            return 2 * (length + width);
        }
        ~Rectangle(){}
};

void printShapeInfo(const Shape* shape) {
    // Implement this function
    cout << "Shape: " << shape->shapeName << endl;
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl << endl;
}
int main() {
    // Create an array of Shape pointers and demonstrate polymorphism
    Shape* shapes[] = { new Circle{4}, new Rectangle{2,2}, new Circle{10} };
    for (Shape*shape : shapes) {
        printShapeInfo(shape);
        delete shape;
        shape = nullptr;
    }
    return 0;
};