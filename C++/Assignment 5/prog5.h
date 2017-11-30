/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 5
 * Assignment Title: Our Friend the Atom
 * Due Date: 10/11/17
 */


/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
*/

#ifndef PROG5_H
#define PROG5_H


#include <iostream> //library for input output operations
#include <string>  //library for using string in the program
#include <vector> //library for making use of vector in our program
#include <cstdlib> //library for making use of random number generator
#include <ctime>  //this header file contains definitions to get and manipulate date and time information.
using namespace std; //header file to include features of standard c++ library.


const unsigned int GRID_SIZE = 25; //defined grid size i.e displayed as row * coloumn

const int low = 1;	//random interval for each ball ie minimum value
const int high = 4;   //random interval for each ball ie maximum value
int noBallsInAir = 1;     //defined for the first ball in the air
int simulationClock = 0;  //defining simulation clock which is incremented for each cycle
int maxBallsInAir = 0;  //defined max balls in the air
const int PRN_CYCLES = 10;	//PRN_CYCLES is used to print the output after every 10 cycles

//function prototyping
void print_stat(const vector< vector<bool> >&traps, const unsigned &maxNoBallsInAir, const unsigned &clock);
void print_grid(const vector< vector<bool> > &traps, const unsigned &clock, const unsigned &noBallsInAir);
unsigned release_balls(vector< vector<bool> >&traps, vector<unsigned> &ballCycles);
void init_sim(vector< vector<bool> >&traps, vector <unsigned> &ballCycles);
void update_cycles(vector<unsigned> &ballCycles);

#endif
