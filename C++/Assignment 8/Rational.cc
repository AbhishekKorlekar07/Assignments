//Rational.cc
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 8
 * Assignment Title: Rational Numbers
 * Due Date: 11/9/17
 */
#include "Rational.h"

//public constructor to create rational object with numerator n and denominator 0
Rational::Rational(const int& n, const int& d){

	//prints error message if denomiator is zero
	if(d == 0){
		cerr<<"Error: division by zero"<<endl;
	}

	if(n == 0){
		num = 0;
		den = 1;
		
	}else if(d != 0){ 
		int g = gcd(abs(n) , abs(d)); // calling gcd function to reduce fraction
		num = n / g;
		den = abs(d) / g;
		if(d < 0){
			num = -num;
		}
	}
}

//gcd function to return the greatest common divisor amongst the variables 
int Rational::gcd(int x, int y){
	int divisor = x % y;
	while( divisor != 0){
 		x = y;
		y = divisor;
		divisor = x % y;
	}
	return y;
}

//copy constructor to copy the object
Rational::Rational(const Rational& r){
	num = r.num;
	den = r.den;	
}

//public assignment operator overrites the existing Rational object with copy of Rational object r
Rational& Rational::operator=(const Rational& r){
	num = r.num;
	den = r.den;
	return *this;
}

//function to overload the operator +=
Rational& Rational::operator+=(const Rational& r){
	num = (num*r.den) + (den*r.num);
	den = den * r.den;
	return *this;
}

//function to overload the operator -=
Rational& Rational::operator-=(const Rational& r){
	num = (num*r.den) - (den*r.num);
	den = den * r.den;

	int g = gcd(abs(num) , abs(den));
	num = num / g;
	den = abs(den) / g;
	if(den < 0){
		num = -num;
	}
	return *this;
}

//function to overload the operator *=
Rational& Rational::operator*=(const Rational& r){
	num *= r.num;
	den *= r.den;	
	return *this;
}

//function to overload the operator /=
Rational& Rational::operator/=(const Rational& r){
	num /= r.num;
	den /= r.den;	
	return *this;
}

//function to overload preincrement operator
Rational& Rational::operator++(){
	num = (num*1) + (den*1);
	den = den * 1;
	return *this;
}

//function to overload predecrement operator
Rational& Rational::operator--(){
	num = (num * 1) - (den * 1);
	den = den * 1;
	return *this;
}

//function to overload post increment operator
Rational Rational::operator++(int unused){
	Rational temp(*this);	
	num = (num*1) + (den*1);
	den = den * 1;
	return temp;
}

//function to overload post decrement operator
Rational Rational::operator--(int unused){
	Rational temp(*this);	
	num = (num*1) - (den*1);
	den = den * 1;
	return temp;
}

//friend function to overload + operator
Rational operator+(const Rational& r1, const Rational& r2){
	Rational temp;
	temp.num = (r1.num * r2.den) + (r1.den * r2.num);
	temp.den = r1.den * r2.den;
	return temp;	
}


//friend function to overload - operator
Rational operator-(const Rational& r1, const Rational& r2){
	Rational temp;
	temp.num = (r1.num * r2.den) - (r1.den * r2.num);
	temp.den = r1.den * r2.den;
	return temp;	
}


//friend function to overload * operator
Rational operator*(const Rational& r1, const Rational& r2){
	Rational temp;
	temp.num = r1.num * r2.num;
	temp.den = r1.den * r2.den;
	return temp;
}


//friend function to overload / operator
Rational operator/(const Rational& r1, const Rational& r2){
	Rational temp;
	temp.num = r1.num * r2.den;
	temp.den = r1.den * r2.num;
	return temp;	
}


//friend function to overload == operator
bool operator==(const Rational& r1, const Rational& r2){
	return (r1.num*r2.den == r1.den*r2.num);
}

//friend function to overload != operator
bool operator!=(const Rational& r1, const Rational& r2){
	return (r1.num*r2.den != r1.den*r2.num);
}

//friend function to overload < operator
bool operator<(const Rational& r1, const Rational& r2){
	return (r1.num*r2.den < r1.den*r2.num);
}

//friend function to overload <= operator
bool operator<=(const Rational& r1, const Rational& r2){
	return (r1.num*r2.den <= r1.den*r2.num);
}

//friend function to overload > operator
bool operator>(const Rational& r1, const Rational& r2){
	return (r1.num*r2.den > r1.den*r2.num);
}

//friend function to overload >= operator
bool operator>=(const Rational& r1, const Rational& r2){
	return (r1.num*r2.den >= r1.den*r2.num);
}

//friend function to overload stream insertion operator
ostream& operator<<(ostream& os, const Rational& r ){
	if(r.den == 1 || r.den == 0){
		os << r.num;
	}else{
		int numerator = r.num;
		int denominator = r.den;
		if(denominator < 0){
			denominator = abs(denominator);
			numerator = -numerator;
		}
		os << numerator << "/" << denominator;
	}
	return os;
}

//friend function to overload stream extraction operator
istream& operator>>(istream& is, Rational& r){
	char a;
	is >> r.num >> a >> r.den;
/*	string line;
	char a;
	if(getline(is, line)){
		cout << "line: " << line << endl;
	}*/
/*	char a;
	string line;
	is >> r.num >> a >> r.den;
	if(a == '\0'){
		if(getline(is, line)){
			cout << "line: " << line << endl;
		}
		string errorMsg;
		cerr<<"Error: line "<< errorMsg <<"contains invalid number" <<endl;
	}
	return is;*/
/*	string slash;
	string line;

	if(getline(is, line)){
		//std::istringstream is(line);
		cout<<"line coming: " << line << "line length: " << line.length() <<endl;

		string lineWithoutSpaces;
		for(unsigned i = 0; i < line.length(); i++){
			if(isdigit(line[i]) || line[i] == '/' || line[i] == '-'){
				lineWithoutSpaces += line[i];
			}
		}

		if(lineWithoutSpaces.find("/") == string::npos || lineWithoutSpaces.find("9") != string::npos){
			if(lineWithoutSpaces.length() == 1){
				char slashCopy = '/';
				int bottomOneNum = 0;
				is >> r.num >> slashCopy >> bottomOneNum;
			}else{
				cerr<<"Error: line "<< line <<"contains invalid number" <<endl;
			}

		}else{
			map <string, bool> myMap;
			myMap["num"] = false;
			myMap["den"] = false;
			string numerator, denominator;
			char slash;
			
			for(unsigned j = 0; j < lineWithoutSpaces.length(); j++){
				if((isdigit(lineWithoutSpaces[j]) || lineWithoutSpaces[j] == '-') && myMap["num"] == false){
					numerator += lineWithoutSpaces[j];
				}else if(lineWithoutSpaces[j] == '/'){
					slash = lineWithoutSpaces[j];
					myMap["num"] = true;
				}else{
					denominator += lineWithoutSpaces[j];
				}
			}
			int numm = stoi(numerator);
			int denn = stoi(denominator);
	//		string combined = numerator + slash + denominator;
			is >> numm >> slash >> denn;
	//		is >> r.num >> slash >> r.den;
		}
	}*/
/*	char one_char;
	int bottomOneNum = 1;
	is >> r.num;
	is >> one_char;
	if(one_char == '/'){
		is >> r.den;
	}else if( one_char != '/'){
		is >> bottomOneNum;
	}*/

	//new code
/*	char c;
	char ln;
	if(c == '/'){
		is >> r.den;
		ln = (is >> ws).peek();
		if(ln == 9){
			cout << "error: line\"" << r.num << c << r.den << " " << ln << ln << ln <<"\" contains invalid number" <<endl;
			is >> 1;
		}
	}else if(c == ':'){
		is >> r.den;
		cout << "Error: line\"" << "   "<< r.num << " " << c << " " << r.den << "\" contains invalid number" << endl;
	}else{
		r.den = 1;
	}*/
	return is;
}
