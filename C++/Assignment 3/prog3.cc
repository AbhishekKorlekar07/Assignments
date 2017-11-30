/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 3
 * Assignment Title: Caesar Cipher Updated
 * Due Date: 09/25/17
 */

/*
 * Here in this program we are encoding the text with the help of caesar cipher method. We have two data files i.e. prog3.d1 (for reading the shift and key values), 
 * with the help of which we are encoding the text in prog3.d2 (for reading the text to encode).
 */

//importing the header file into our program what we created. Header file consists of constants and prototypes.
#include "prog3.h"

/*
 * In this function for charachter c of the shift value and the second shift value obtained from the key, it returns the new position of c after shifting.
 */
int new_position(const char& c, const int& shift, const string& key){
	int newPos = 0;
	int charachterIndex = alphabets.find(toupper(c)); //getting the charachter Index of char c in alphabets string.
	char valueAtIndexInKey = key[charachterIndex]; //getting the value at index(obtained from the step above) in the key string.
	int difference = ((int(toupper(c)) - int(valueAtIndexInKey)) + shift); //calculating the difference inorder to shift letters. 
	if(difference > 0){
		for(int var = charachterIndex + 1; var <= (charachterIndex + difference); var++){
			newPos = var % 26;
		}
	}else if(difference < 0){
		while(difference < 0){
			(charachterIndex == 0) ? charachterIndex = 25 : charachterIndex -=1;
			newPos = charachterIndex % 26;
			difference +=1;
		}
	}else{
		newPos = charachterIndex;
	}

	return newPos;
}

/*
 * This function returns a new string formed by shifting every letter in str forward the number of letters indicated by shift and key, cycling back to the
 * beginning of the alphabet if necessary. To implement shifting this function calls the auxillary function new_position
 * */
string encodeCaesarCipher(string str, const int& shift, const string& key){
	string encodedString;
	for(unsigned int i = 0; i < str.length(); i++){
		//check for the charachter is a letter or not
		if(isalpha(str[i])){ 
			//here check is for lower case & upper case letters and passing the charachter to the new_position function which returns the new position of c
			encodedString += (islower(str[i])) ? tolower(alphabets[new_position(str[i], shift, key)]) : alphabets[new_position(str[i], shift, key)];	
		}else{
			encodedString += str[i];
		}
	}
	return encodedString;
}

/*this function opens up the second file ie prog3.d2 to read the text to encode and if unsuccessful it  displays an error message. It prints out the shift and key
 * values and gets the text input from the data file. To process each input file it calls encodeCaesarCipher function and prints out the encrypted text returned 
 * by this function and finally it closes the data file
*/

void process_infile(const int& shift, const string& key){
	string textToEncode;
	string encryptedText;
	ifstream secondFile; //here creating the file object to read text to encode from the second file
       	secondFile.open(SECONDFILE); 
	if(secondFile.is_open()){ //after opening the file, condition to check if the file is openend.
		while(getline(secondFile, textToEncode)){  // reading the text from the second data file.
			encryptedText += encodeCaesarCipher(textToEncode, shift, key) + "\n"; //here encodeCaesarCipher function is called which returns encodedString
		}
		secondFile.close();
	}else if(secondFile.fail()){
		cout<<"Error in file"<<endl;
		exit(EXIT_FAILURE);
	}

	//printing the shift, key and encryptedText
	cout<<"shift =  "<<shift<<endl;
	cout<<"key = "<<'"'<<key<<'"'<<"\n"<<endl;
	cout<<encryptedText<<endl;
}

int main(){
	int shift;
	string key;
	ifstream firstFile; //here we are creating the object of ifstream to read from file prog3.d1
       	firstFile.open(FIRSTFILE); //opening the file prog3.d1
	if(firstFile.is_open()){  //condition to check if the file is opened.
		while(firstFile>>shift>>key){   //here we are reading the shift and key value  from the file one after another till the end of file.
			process_infile(shift, key); //here process_infile function is called where we are passing the shift and key values from the file.
		}
		firstFile.close();
	}else if(firstFile.fail()){ //condition which satisfies in case any error occurs in the file.
		cout<<"Error in file"<<endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
