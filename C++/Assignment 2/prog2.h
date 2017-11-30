/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 2
 * Assignment Title: Find Perfect Numbers and display its divisors
 * Due Date: 09/14/17
 */

/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
 * */


#ifndef PROG2_H
#define PROG2_H

#include <iostream> //library for input output operations
#include <string> //library for using string in our program
using namespace std; //header file to include features of c++ standard library


bool isPerfect(const unsigned int number); //function prototyping ie declaring the function onto the header file who has its definition in prog2.cc
void divisors(const unsigned int divisor);

const unsigned int lastValue = 9999; /*defined a constant in the header file so that it can be used by multiple source files
and later if we need to change this value in that case we will have to just make the change over here */

#endif
