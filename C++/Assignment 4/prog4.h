/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 4
 * Assignment Title: Removing comments from source file
 * Due Date: 10/02/17
 */


/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
*/

#ifndef PROG4_H
#define PROG4_H
#define INFILE "/home/cs689/progs/17f/p4/prog4-in.cc" //providing path to the input file which we will use to remove comments
#define OUTFILE "prog4-out.cc" //providing the output file name

#include <iostream> //library for input and output operations
#include <string>   //library for using strings in the program
#include <fstream>  //library for performing reading and writing operations on the file
using namespace std; //header file to include features of standard c++ library.

//function prototyping
void close_files(ifstream& is, ofstream& os);
void process_data(ifstream& is, ofstream& os);
void open_files(ifstream& is, ofstream& os);


#endif
