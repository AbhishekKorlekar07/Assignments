/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 3
 * Assignment Title: Caesar Cipher Updated
 * Due Date: 09/25/17
 */


/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
*/

#ifndef PROG3_H
#define PROG3_H
#define FIRSTFILE "/home/cs689/progs/17f/p3/prog3.d1" //adding the path for data file which contains shift and the key
#define SECONDFILE "/home/cs689/progs/17f/p3/prog3.d2" //adding the path for the data file which consists of text to encode

#include <iostream> //library for input & output operations
#include <string> //library for using strings in our program
#include <fstream> //library for reading and writing operations on the file
using namespace std; //header file to include features of c++ standard library.

//function prototyping
int new_position(const char& c, const int& shift, const string& key);
string encodeCaesarCipher(string str, const int& shift, const string& key);
void process_infile(const int& shift, const string& key);


//defining a const of alphabets which is used to get the get the charachter Index and also to get the value at index after shifting. 
const string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


#endif

