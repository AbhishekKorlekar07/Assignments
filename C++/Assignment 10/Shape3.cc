
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 10
 * Assignment Title: Geometric Shapes
 * Due Date: 11/28/17
 */

//including the header file where all the definations are present for three dimmensional shapes.
#include "/home/cs689/progs/17f/p10/Shape3.h"

//implementation for cube class constructor.
Cube::Cube ( const double& len){
	length = len;
	width = len;
}

//implementation for cube class copy constructor.
Cube::Cube( const Cube& cub) : Square(cub){
	length = cub.length;
	width = cub.length;
}

//implementation for cube class assignment operator.
Cube& Cube::operator= ( const Cube& cub){
	length = cub.length;
	width = cub.width;
	return *this;
}

//implementation for cube class += operator.
Cube& Cube::operator+= ( const Cube& cub){
	length += cub.length;
	width += cub.width;
	return *this;
}

//implementation for cube class destructor.
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Cube::~Cube(){

}

//implementation for cube class perimeter method.
double Cube::perimeter() const{
	double result = 0;
	return result;
}

//implementation for cube class area method.
double Cube::area() const{
	double result = (6 * Square::area());
	return result;
}

//implementation for cube class volume method.
double Cube::volume() const{
	double result = length * Square::area();
	return result;
}

//implementation for cube class print method.
void Cube::print() const{
	cout << "length = " << length;
}

//implementation for box class constructor.
Box::Box ( const double& a, const double& b, const double& c){
	length = a;	
	width = b;
	height = c;
}

//implementation for box class copy constructor.
Box::Box ( const Box& boxObj) : Rectangle(boxObj){
	length = boxObj.length;
	width = boxObj.width;
	height = boxObj.height;
}

//implementation for box class assignment operator.
Box& Box::operator= ( const Box& boxObj){
	length = boxObj.length;
	width = boxObj.width;
	height = boxObj.height;
	return *this;
}

//implementation for box class += operator.
Box& Box::operator+= ( const Box& boxObj){
	length += boxObj.length;
	width += boxObj.width;
	height += boxObj.height;
	return *this;
}

//implementation for box class destructor.
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Box::~Box (){

}

//implementation for box class perimter method.
double Box::perimeter() const{
	double res = 0;
	return res;	
}

//implementation for box class area method.
double Box::area() const{
	double result = (2 * Rectangle::area() + (height * Rectangle::perimeter()));
	return result;

}

//implementation for box class volume method
double Box::volume() const{
	double result = height * Rectangle::area();
	return result;
}

//implementation for box class print method.
void Box::print() const{
	cout << "length = " << length << " : " <<"width = " << width << " : " << "height = " << height;
}

//implementation for cylinder class constructor.
Cylinder::Cylinder ( const double& rad, const double& h){
	radius = rad;
	height = h;
}

//implementation for cylinder class copy constructor.
Cylinder::Cylinder ( const Cylinder& cylinderObj) : Circle(cylinderObj){
	radius = cylinderObj.radius;
	height = cylinderObj.height;
}

//implementation for cylinder class assignment operator.
Cylinder& Cylinder::operator= ( const Cylinder& cylinderObj){
	radius = cylinderObj.radius;
	height = cylinderObj.height;
	return *this;
}

//implementation for cylinder class += operator.
Cylinder& Cylinder::operator+= ( const Cylinder& cylinderObj){
	radius += cylinderObj.radius;
	height += cylinderObj.height;
	return *this;
}

//implementation for cylinder class destructor.
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Cylinder::~Cylinder(){

}

//implementation for cylinder class perimeter method.
double Cylinder::perimeter() const{
	double res = 0;
	return res;	
}

//implementation for cylinder class area method.
double Cylinder::area() const{
	double a1 = height * Circle::perimeter();
	double result = 2 * Circle::area() + a1;
	return result;
}

//implementation for cylinder class volume method.
double Cylinder::volume() const{
	double result = height * Circle::area();
	return result;
}

//implementation for cylinder class print method.
void Cylinder::print() const{
	cout << "radius = " << radius << " : " << "height = " << height;
}


//implementation for cone class constructor.
Cone::Cone ( const double& rad, const double& h){
	radius = rad;
	height = h;
}

//implementation for cone class copy constructor.
Cone::Cone ( const Cone& coneObj) : Circle(coneObj){
	radius = coneObj.radius;
	height = coneObj.height;
}

//implementation for cone class assignment operator.
Cone& Cone::operator= ( const Cone& coneObj){
	radius = coneObj.radius;
	height = coneObj.height;
	return *this;
}

//implementation for cone class += operator.
Cone& Cone::operator+= ( const Cone& coneObj){
	radius += coneObj.radius;
	height += coneObj.height;
	return *this;
}

//implementation for cone class destructor.
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Cone::~Cone(){

}

//implementation for cone class perimeter method.
double Cone::perimeter() const{
	double res = 0;
	return res;
}

//implementation for cone class area method.
double Cone::area() const{
	double s = sqrt((radius * radius) + (height * height));
	double a1 = ((s * Circle::perimeter())/2);
	double result = Circle::area() + a1;
	return result;
}

//implementation for cone class volume method.
double Cone::volume() const{
	double result = ((height * Circle::area())/3);
	return result;
}

//implementation for cone class print method.
void Cone::print() const{
	cout << "radius = " << radius << " : " << "height = " << height;
}


//implementation for sphere class constructor.
Sphere::Sphere ( const double& rad){
	radius = rad;
}

//implementation for sphere class copy constructor.
Sphere::Sphere ( const Sphere& sphereObj) : Circle(sphereObj){
	radius = sphereObj.radius;	
}

//implementation for sphere class assignment operator.
Sphere& Sphere::operator= ( const Sphere& sphereObj){
	radius = sphereObj.radius;
	return *this;
}

//implementation for sphere class += operator.
Sphere& Sphere::operator+= ( const Sphere& sphereObj){
	radius += sphereObj.radius;
	return *this;
}

//implementation for sphere class destructor.
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Sphere::~Sphere(){

}

//implementation for sphere class area method.
double Sphere::area() const{
	double result = 4 * Circle::area();
	return result;
}

//implementation for sphere class volume method.
double Sphere::volume() const{
	double result = (4 * (radius * Circle::area())) / 3;
	return result;
}

//implementation for tetrahedron class constructor
Tetrahedron::Tetrahedron ( const double& p){
	a = p;
	b = p;
	c = p;
}
 
//implementation for tetrahedron class copy constructor
Tetrahedron::Tetrahedron ( const Tetrahedron& tetra) : equTriangle(tetra){
	a = tetra.a;
	b = tetra.b;
	c = tetra.c;
}

//implementation for tetrahedron class assignment operator
Tetrahedron& Tetrahedron::operator= ( const Tetrahedron& tetra){
	a = tetra.a;
	b = tetra.b;
	c = tetra.c;
	return *this;
}

//implementation for tetrahedron class += operator
Tetrahedron& Tetrahedron::operator+= ( const Tetrahedron& tetra){
	a += tetra.a;
	b += tetra.b;
	c += tetra.c;
	return *this;
}

//implementation for tetrahedron class destrcutor
//Since we dont have any dynamic memmory allocated we are not making use of the delete keyword
Tetrahedron::~Tetrahedron(){

}

//implementation for tetrahedron class perimeter method
double Tetrahedron::perimeter() const{
	double res = 0;
	return res;
}

//implementation for tetrahedron class area method
double Tetrahedron::area() const{
	double result = 4 * equTriangle::area();
	return result;
}

//implementation for tetrahedron class volume method
double Tetrahedron::volume() const{
	double val = a * b * c;
	double result = (val / (6 * sqrt(2)));
	return result;
}

