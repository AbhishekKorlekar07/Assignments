#include "/home/cs689/progs/17f/p10/Shape.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#ifndef SHAPE2_H
#define SHAPE2_H
const double PI = ( 4 * atan(1) );


class Rectangle{
	public:
		Rectangle(const double& a = 0, const double& b = 0);
		Rectangle(const Rectangle& rect);
		Rectangle& operator= (const Rectangle& rect);
		Rectangle& operator+= (const Rectangle& rect);
		~Rectangle();
		double perimeter() const;
		double area() const;
		void print() const;
	protected:
		double length;
		double width;
};

class Circle{
	public:
		Circle(const double& rad = 0);
		Circle(const Circle& cir);
		Circle& operator= (const Circle& cir);
		Circle& operator+= (const Circle& cir);
		~Circle();
		double perimeter() const;
		double area() const;
		void print() const;
	protected:
		double radius;
};

class Triangle{
	public:
		Triangle(const double& p = 0, const double& q = 0, const double& r = 0);
		Triangle(const Triangle& tri);
		Triangle& operator= (const Triangle& tri);
		Triangle& operator+= (const Triangle& tri);
		~Triangle();
		double perimeter() const;
		double area() const;
		void print() const;
	protected:
		double a, b, c;
};

class Square : public Rectangle{
	public:
		Square(const double& len = 0);
		Square(const Square& sqr);
		Square& operator= (const Square& sqr);
		Square& operator+= (const Square& sqr);
		~Square();
		void print() const;
};

class rightTriangle : public Triangle{
	public:
		rightTriangle(const double& p = 0, const double& q = 0);
		rightTriangle(const rightTriangle& rightTri);
		rightTriangle& operator= (const rightTriangle& rightTri);
		rightTriangle& operator+= (const rightTriangle& rightTri);
		~rightTriangle();
		void print() const;
};

class equTriangle : public Triangle{
	public:
		equTriangle(const double& p = 0);
		equTriangle(const equTriangle& equTri);
		equTriangle& operator= (const equTriangle& equTri);
		equTriangle& operator+= (const equTriangle& equTri);
		~equTriangle();
		void print() const;
};

#endif
