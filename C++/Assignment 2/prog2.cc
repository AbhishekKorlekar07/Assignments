/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 2
 * Assignment Title: Find Perfect Numbers and display its divisors
 * Due Date: 09/14/17
 */


/*
 * Here in this program we are looking for perfect numbers in the range from 1 - 9999. Once a perfect number is found we are displaying its divisors along
 * with it in the form of n = d1 + d2 + d3 .... dM, where n is the perfect number and d1 - dM are list of divisors.
 */


//importing the header file into our program what we created. Header file consits of constants and prototypes.
	#include "prog2.h"


	string divisorsList; //declaring this variable so that we can store the list of divisors onto this string
	unsigned int total; //this variable is used to sum all of the divisors and check with the number passed ie whether they match or not.



	//divisors function to generate a list of divisors
	void divisors(const unsigned int divisor){
		divisorsList.append(" + " + to_string(divisor)); //appending the divisor to the string
	}

	/* This is a function defination that takes an input number one after another and returns true if the number passed 
	is a perfect number or false otherwise.*/
	bool isPerfect(const unsigned int number){
		divisorsList = "";
		total = 0;
		for(unsigned int i = 1; i < number; i++){
			if((number % i) == 0){
				divisors(i);
				total += i;
			}
		}

		return (number == total) ? true : false; //returns true if number passed is a perfect number else it returns false
	}		


	int main(){
		bool result; //variable to store the result of isPerfect function.
		
		/*this loop iterates from 1 - lastValue (defined a constant in the header file). Everytime it passes the value of i to the isPerfect function
		and gets the result ie true or false and displays its divisors if the number is a perfect Number*/
		for(unsigned int i = 1; i <= lastValue; i++){ 
			result = isPerfect(i);
			if(result){
				cout<<i<<" = "<<divisorsList.erase(0,2)<<endl; //here printing  the list of divisors from the variable divisorsList.
			}
		}
	}
