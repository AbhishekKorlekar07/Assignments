#include "Shape2.h" 
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#ifndef SHAPE3_H
#define SHAPE3_H

class Cube : public Square{
	public:
		Cube ( const double& len = 0 );
		Cube ( const Cube& cub);
		Cube& operator= ( const Cube& cub);
		Cube& operator+= ( const Cube& cub);
		~Cube ( );
//		double perimeter() const
		double area() const;
		double volume() const;
		void print() const;		
};

class Box : public Rectangle{
	public:
		Box ( const double& a = 0, const double& b = 0, const double& c = 0 );
		Box ( const Box& boxObj);
		Box& operator= ( const Box& boxObj);
		Box& operator+= ( const Box& boxObj);
		~Box ( );
//		double perimeter() const;
		double area() const;
		double volume() const;
		void print() const;		

	private:
		double height;
};

class Cylinder : public Circle{
	public:

		Cylinder ( const double& rad = 0, const double& h = 0 );
		Cylinder ( const Cylinder& cylinderObj);
		Cylinder& operator= ( const Cylinder& cylinderObj);
		Cylinder& operator+= ( const Cylinder& cylinderObj);
		~Cylinder ();
//		double perimeter() const;
		double area() const;
		double volume() const;
		void print() const;		
	private:
		double height;
};

class Cone : public Circle{
	public:
		Cone ( const double& rad = 0, const double& h = 0 );
		Cone ( const Cone& coneObj);
		Cone& operator= ( const Cone& coneObj);
		Cone& operator+= ( const Cone& coneObj);
		~Cone();
//		double perimeter() const;
		double area() const;
		double volume() const;
		void print() const;		
	private:
		double height;
};

class Sphere : Circle{
	public:
		Sphere ( const double& rad = 0 );
		Sphere ( const Sphere& sphereObj);
		Sphere& operator= ( const Sphere& sphereObj);
		Sphere& operator+= ( const Sphere& sphereObj);
		~Sphere();
		double area() const;
		double volume() const;
};

class Tetrahedron : public equTriangle{
	public:
		Tetrahedron ( const double& p = 0 );
		Tetrahedron ( const Tetrahedron& tetra);
		Tetrahedron& operator= ( const Tetrahedron& tetra);
		Tetrahedron& operator+= ( const Tetrahedron& tetra);
		~Tetrahedron();
//		double perimeter() const;
		double area() const;
		double volume() const;
};

#endif
