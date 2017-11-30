
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 6
 * Assignment Title: The Date Class
 * Due Date: 10/24/17
 */

#include "Date.h" //to include the header file in our file


//class constructor to set month, day and year to values passed and if not passed set to default values.
Date::Date(const string& m, const int& d, const int& y){
	month = m;
	day = d;
	year = y;
	Month();	
}

//function to set the month component of the date object
void Date::setMonth(const string& m){
	month = m;
	Month();	
}

//function to set the day component of the date object
void Date::setDay(const int& d){
	day = d;
}

//function to set the year component of the date object
void Date::setYear(const int& y){
	year = y;
}

//function to return the month component of the date object
string Date::getMonth() const{
	return month;	
}

//function to return the day function of the date object
int Date::getDay() const{
	return day;	
}

//function to return the year component of the date object
int Date::getYear() const{
	return year;	
}

//function to convert the first letter of the month component of the date object to uppercase and the rest to lower case.
void Date::Month(){
	for(unsigned int i = 0; i < month.length(); i++){
		if(i == 0){
			month[i] = toupper(month[i]);
		}else{
			month[i] = tolower(month[i]);
		}
	}	
}

//function to check a date is valid or not by checking each component indivisually. ie for month (isValidMonth()) to determine that it is a valid month, year (by checking that it is greater than 1 and days by checking the day component has a valid value between the month range
bool Date::isValidDate() const{
	bool isValidDateResult;
	int noOfDays = daysInMonth(month);
	//checking if the year is valid
	if(year >= 1 && isValidMonth() && (day >= 1 && day <= noOfDays)){
		isValidDateResult = true;
	}else{
		isValidDateResult = false;
	}
	return isValidDateResult;
}

//function to check whether a month is valid by checking the month in the vector of months
bool Date::isValidMonth() const{
	bool flag = false;
	for(unsigned int i = 0; i < months.size(); i++){
		if(months[i] == month){
			flag = true;
			break;
		}
	}
	return flag;
}

//function to get the number of months in the month component of date object 
int Date::daysInMonth(const string& m) const{
	bool isLeapYearResult;
	int noOfDaysInMonth;

	if(m == "February"){
		isLeapYearResult = isLeapYear(); //calling isLeapYear function to get correct number of days in february month
		(isLeapYearResult) ? noOfDaysInMonth = 29 : noOfDaysInMonth = 28; 	
	}else if(m == "September" || m == "April" || m == "June" || m == "November"){
		noOfDaysInMonth = 30;
	}else{
		noOfDaysInMonth = 31;
	}

	return noOfDaysInMonth;
}


//function to check whether the year is a leap year
bool Date::isLeapYear() const{
	bool isLeapYearResult;

	if((year % 4) == 0){
		if((year % 100) == 0){
			if((year % 400) == 0){
				isLeapYearResult = true;
			}else{
				isLeapYearResult = false;
			}
		}else{
			isLeapYearResult = true;
		}
	}else{
		isLeapYearResult = false;	
	}
	return isLeapYearResult;
}

//function to convert the month component of the date object to the format dd-mm-yyyy
string Date::toString() const{
	return intToString(day) + "-" + month.substr(0,3) + "-" + intToString(year);	
}

//funtion to convert the integer to string and return the string value
string intToString(const int& n){
	return to_string(n);
}

/*this function overloads tbe extraction operator >>. It reads the individual date components from stream is to the date object d, where date can be entered in the  
 * form month day year or month day, year. Once it reads the value from istream it assigns to the Date objet components.
 */
istream& operator >> (istream& is, Date& d){
	string line;
	string Mon;
	string DayAndYear;

	//getting the value from the is stream
	getline(is, line);
	for(unsigned int i = 0; i < line.length(); i++){
		if(isalpha(line[i])){
			Mon += line[i];
		}else if(isdigit(line[i])){
			DayAndYear += line[i];	
		}
	}
	d.month = Mon; //setting the month component of date object to month from the is stream.
	try{
		d.day = stoi(DayAndYear.substr(0,2)); //setting the day component of date object to day from the is stream.
		d.year = stoi(DayAndYear.substr(2, DayAndYear.length())); //setting the year component of date object to year from the is stream.
	}catch(const invalid_argument& a){}
	return is;
}


/* 
 *This function overloads the insertion operator <<. It gets the individual components from the date object and to the stream os in the form month day, year
 * */
ostream& operator << (ostream& os, const Date& d){
	string dateValue;
	dateValue = d.month + " " + to_string(d.day) + ", " + to_string(d.year);
	os<<dateValue;
	return os;		
}


