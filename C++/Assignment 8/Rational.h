/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 8
 * Assignment Title: Rational Numbers
 * Due Date: 11/9/17
 */

/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
*/

#ifndef RATIONAL_H
#define RATIONAL_H 

#include <iostream> //library for input output operations
#include <string>   //library for using string in program
#include <fstream>  //library for making use of istream and ostream operations
#include <vector>  //library for making use of vector in our program
#include <exception>
#include <map>

using namespace std; //header file to include features of standard c++ library

class Rational{
	//function prototyping
	public:
		Rational(const int& n = 0, const int& d = 1); //public constructor 
		Rational(const Rational& r);	//public copy constructor
		Rational& operator=(const Rational& r);//public assignment operator
		Rational& operator+=(const Rational& r);
		Rational& operator-=(const Rational& r);
		Rational& operator*=(const Rational& r);
		Rational& operator/=(const Rational& r);
		Rational& operator++();
		Rational& operator--();
		Rational operator++(int unused);
		Rational operator--(int unused);
		friend Rational operator+(const Rational& r1, const Rational& r2);
		friend Rational operator-(const Rational& r1, const Rational& r2);
		friend Rational operator*(const Rational& r1, const Rational& r2);
		friend Rational operator/(const Rational& r1, const Rational& r2);
		friend bool operator==(const Rational& r1, const Rational& r2);
		friend bool operator!=(const Rational& r1, const Rational& r2);
		friend bool operator<(const Rational& r1, const Rational& r2);
		friend bool operator<=(const Rational& r1, const Rational& r2);
		friend bool operator>(const Rational& r1, const Rational& r2);
		friend bool operator>=(const Rational& r1, const Rational& r2);
		friend ostream& operator<<(ostream& os, const Rational& r );
		friend istream& operator>>(istream& is, Rational& r);

	private:
		int num;
		int den;
		//function to get the greatest common divisor
		int gcd(int x, int y);
};
#endif
