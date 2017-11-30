/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 7
 * Assignment Title: The Date Class Phase 2
 * Due Date: 11/1/17
 */

/*
 * Here header file is declared to avoid repetations and hold declarations for other files to use.
*/

#ifndef DATE_H
#define DATE_H 

#include <iostream> //library for input output operations
#include <string>   //library for using string in program
#include <fstream>  //library for making use of istream and ostream operations
#include <vector>  //library for making use of vector in our program

using namespace std; //header file to include features of standard c++ library
const string MONTH = "January"; //defining default month value
const int DAY = 1;		//defining default day value
const int YEAR = 2000;		//defining default year value

//vector of months to check of the month of a Date object is valid or not
const vector<string> months{"January","February","March","April","May","June","July","August","September","October","November","December"};

string intToString(const int& n); //function prototyping

//declaring date class and its member function protototyping
class Date{
	private:
		string month;
		int day;
		int year;
		bool isValidMonth() const; //to check whether a month is valid
		int daysInMonth(const string& m, int y) const; //to get the number of days in a month
		bool isLeapYear(const int YEAR) const; //for checking that a year is a leap year
		int monthIndex(const string m);
	
	public:
		Date(const string& m = MONTH, const int& d = DAY, const int& y = YEAR); //class constructor
		void setMonth( const string& m); 	//setting the month of date object
		void setDay( const int& d);		//setting the day of the date object
		void setYear( const int& y);		//setting the year of the date object
		string getMonth() const;		//getter for getting the month of date object
		int getDay() const;			//getter for getting the day if the date object
		int getYear() const;			//getter for getting the year of the date object
		void Month();				//convert month of by changing first letter to uppercase and the rest to lowercase
		bool isValidDate() const;		//check whether the date is valid
		string toString() const;		//convert date to the format of dd-mm-yyyy
		friend istream& operator >> (istream& is, Date& d);		//operator overloading function to overload the operator >>
		friend ostream& operator << (ostream& os, const Date& d);	//operator overloading function to overload the operator <<
	 	Date& addYear(const int& n);		//this function is used to n number of years to the date object
		Date(const Date& d);			//this constructor can be used to create new date object from the copy of date object d
		Date& operator= (const Date& d);	//this assignment operator is used to overwrite an existing date object with copy of Date object d
		Date& addDay(const int& n);		//this function is used to add n number of days to the date object
		Date& addMonth(const int& n);		//this function is used to add n number of months to the date object
		int dayIndex() const;			//this function is used to get the index value of the date object from the date January 1, 1
};


unsigned dateDiff ( const Date& d1, const Date& d2 );	// this function is used to get difference between the two dates given
int findDaysInMon(const string& m, const int y);	//this non - member function is to find number of days in a month
int getMonInd(const string m);				//this non - member function is used to get the index of a month
string nextOrPrevMonth(string currentMonth, bool findNextMonth);	//this function is to get the next month or prev month based on the current month passed

#endif
