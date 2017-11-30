
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 10
 * Assignment Title: Geometric Shapes
 * Due Date: 11/28/17
 */

//including the header file where all the definations are present for two dimmensional shapes.
#include "/home/cs689/progs/17f/p10/Shape2.h"

//implementation for Rectangle constructor
Rectangle::Rectangle(const double& a, const double& b){
	length = a;
	width = b;
}

//implementation for Rectangle copy constructor
Rectangle::Rectangle(const Rectangle& rect){
	length = rect.length;
	width =	rect.width;
}

//implementation for assignment operator for Rectangle class
Rectangle& Rectangle::operator= (const Rectangle& rect){
	length = rect.length;
	width = rect.width;
	return *this;
}

//implementation for overloading += operator for Rectangle class.
Rectangle& Rectangle::operator+= (const Rectangle& rect){
	length += rect.length;
	width += rect.width;
	return *this;
}

//destructor for rectangle class
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Rectangle::~Rectangle(){

}

//implementation of perimeter for rectangle class
double Rectangle::perimeter() const{
	double result;
	result = 2 * (length + width);
	return result;
}

//implementation of area method for rectangle class
double Rectangle::area() const{
	double result;
	result = length * width;
	return result;
}

//implementation of print menthod for Rectangle class
void Rectangle::print() const{
	cout << "length = " << length << " : " <<"width = " << width;
}


//implementation for circle class constructor
Circle::Circle(const double& rad){
	radius = rad;
}

//implementation for circle class copy constructor
Circle::Circle(const Circle& cir){
	radius = cir.radius;
}

//implementation for circle class assignment operator
Circle& Circle::operator= (const Circle& cir){
	radius = cir.radius;
	return *this;
}

//implementation for += operator for the class Circle
Circle& Circle::operator+= (const Circle& cir){
	radius += cir.radius;
	return *this;
}

//implementation for the circle class destructor
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Circle::~Circle(){

}

//implementation for the circle class perimeter method.
double Circle::perimeter() const{
	double result;
	result = 2 * PI * radius;
	return result;
}

//implementation for the circle class area method.
double Circle::area() const{
	double result;
	result = PI * radius * radius;
	return result;
}

//implementation for the circle class print method.
void Circle::print() const{
	cout << "radius = " << radius;
}

//implementation for triangle class constructor
Triangle::Triangle(const double& p, const double& q, const double& r){
	a = p;
	b = q;
	c = r;
}

//implementation for triangle class copy constructor.
Triangle::Triangle(const Triangle& tri){
	a = tri.a;
	b = tri.b;
	c = tri.c;
}

//implementation for triangle class assignment operator
Triangle& Triangle::operator= (const Triangle& tri){
	a = tri.a;
	b = tri.b;
	c = tri.c;
	return *this;
}

//implementator for triangle class += operator 
Triangle& Triangle::operator+= (const Triangle& tri){
	a += tri.a;
	b += tri.b;
	c += tri.c;
	return *this;
}

//implementation of the triangle class destructor
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Triangle::~Triangle(){

}

//implementator of the triangle class perimeter method.
double Triangle::perimeter() const{
	double result;
	result = a + b + c;
	return result;	
}

//implementation of triangle class area method.
double Triangle::area() const{
	double semiPerimeter = (a + b + c ) / 2;
	double result = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
	return result;
}

//implementation of triangle class print method
void Triangle::print() const{
	cout << "a = " << a << " : b = " << b << " : c = " << c;
}

//implementation of square class constructor.
Square::Square(const double& len){
	length = len;
	width = len;
}

//implementation of square class copy constructor.
Square::Square(const Square& sqr) : Rectangle(sqr){
	length = sqr.length;
	width = sqr.width;
}

//implementation of square class assignment operator.
Square& Square::operator= (const Square& sqr){
	length = sqr.length;
	width = sqr.width;
	return *this;
}

//implementation of square class += operator.
Square& Square::operator+= (const Square& sqr){
	length += sqr.length;
	width += sqr.width;
	return *this;
}

//implementation of square class destructor.
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Square::~Square(){

}

//implementation of square print method.
void Square::print() const{
	cout << "length = " << length;
}

//implementation of rightTriangle class constructor
rightTriangle::rightTriangle(const double& p, const double& q){
	a = p;
	b = q;
	c = sqrt((a * a) + (b * b));
}

//implementation of rightTriangle class copy constructor
rightTriangle::rightTriangle(const rightTriangle& rightTri) : Triangle(rightTri){
	a = rightTri.a;
	b = rightTri.b;
	c = rightTri.c;
}

//implementation of rightTriangle class assignment operator
rightTriangle& rightTriangle::operator= (const rightTriangle& rightTri){	
	a = rightTri.a;
	b = rightTri.b;
	c = rightTri.c;
	return *this;
}

//implementation of rightTriangle class += operator
rightTriangle& rightTriangle::operator+= (const rightTriangle& rightTri){
	a += rightTri.a;
	b += rightTri.b;
	c += rightTri.c;
	return *this;
}

//implementation of rightTriangle class destructor
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
rightTriangle::~rightTriangle(){

}

//implementation of rightTriangle class print method
void rightTriangle::print() const{
	cout << "length = " << a << " : " << "height = " << b;
}

//implementation of equilater class constructor
equTriangle::equTriangle(const double& p){
	a = p;
	b = p;
	c = p;
}

//implementation of equilater class copy constructor
equTriangle::equTriangle(const equTriangle& equTri) : Triangle(equTri){
	a = equTri.a;
	b = equTri.b;
	c = equTri.c;
}

//implementation of equilater class assignment operator
equTriangle& equTriangle::operator= (const equTriangle& equTri){
	a = equTri.a;
	b = equTri.b;
	c = equTri.c;
	return *this;
}

//implementation of equilater class += operator
equTriangle& equTriangle::operator+= (const equTriangle& equTri){
	a += equTri.a;
	b += equTri.b;
	c += equTri.c;
	return *this;
}

//implementation of equilater class destructor
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
equTriangle::~equTriangle(){

}

//implementation of equilater class print method
void equTriangle::print() const{
	cout <<"length = " << a;
}

