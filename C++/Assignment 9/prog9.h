
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 9
 * Assignment Title: A Simple Calculator
 * Due Date: 11/20/17
 */

/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
*/

#ifndef PROG9_H
#define PROG9_H

#include <iostream> //library for input and output operations
#include <string>   //libary for making use of string in the program
#include <stack>	//libary for making use of stack in our program
#include <iomanip>	//library for manipulating the input and output
#include <algorithm>	//library to be used on the ranges of elements.
#include <cmath>	//library declares a set of functions to compute common mathematical operations and transformations
#include <fstream>	//library for input/output stream class.
#include <sstream>	//library for input/output string stream.
using namespace std;	//header file to include features of standard c++ library

//function prototyping
bool unarySign(const char& c, const string& token, const unsigned& i);
bool floatPoint(const char& c, const string& token, const unsigned& i);
//double getNumber(const char& c, const string& token, unsigned& i, const bool& floatPointFlag);
void process_token(const string& token, stack <double>& S);
double stringToDouble(string line);
bool isValidOperator(const char& c);
double operation(const char& c, const double& x, const double& y);
double popStack(stack<double>& S);
void printResult(const stack<double>& S);
void emptyStack(stack<double>& S);


#endif
