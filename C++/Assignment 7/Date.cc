
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 7
 * Assignment Title: The Date Class Phase 2
 * Due Date: 11/1/17
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
	int noOfDays = daysInMonth(month, year);
//	if(year >= 1 && isValidMonth() && (day >= 1 && day <= noOfDays)){
	if((year > 0 || year < 0) && isValidMonth() && (day >= 1 && day <= noOfDays)){
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
int Date::daysInMonth(const string& m, int y) const{
	bool isLeapYearResult;
	int noOfDaysInMonth;

	if(m == "February"){
		isLeapYearResult = isLeapYear(y); //calling isLeapYear function to get correct number of days in february month
		(isLeapYearResult) ? noOfDaysInMonth = 29 : noOfDaysInMonth = 28; 	
	}else if(m == "September" || m == "April" || m == "June" || m == "November"){
		noOfDaysInMonth = 30;
	}else{
		noOfDaysInMonth = 31;
	}

	return noOfDaysInMonth;
}


//function to check whether the year is a leap year
bool Date::isLeapYear(const int YEAR) const{
	bool isLeapYearResult;

	if((YEAR % 4) == 0){
		if((YEAR % 100) == 0){
			if((YEAR % 400) == 0){
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

//this copy constructor is used to create new Date object from the copy of object d
Date::Date(const Date& d){
	year = d.year;
	month = d.month;
	day = d.day;
}

//this public assignment operator overwrites an existing object with copy of Date object d
Date& Date::operator=(const Date& d){	
	year = d.year;
	month = d.month;
	day = d.day;
	return *this;
}

//this non member function can be used to get the next month ot the prev month from the current month passed 
string nextOrPrevMonth(string currentMonth, bool findNextMonth){
	int index;
	for(unsigned int i = 0; i < months.size(); i++){
		if(months[i] == currentMonth){
			index = i;
			break;
		}
	}
	if(findNextMonth){
		string nextMonth;
		(index == 11) ? nextMonth = "January" : nextMonth = months.at(index + 1);
		return nextMonth;
	}else{
		string prevMonth;
		(index == 0) ? prevMonth = "December" : prevMonth = months.at(index - 1);
		return prevMonth;
	}
}

//this private function returns the index value of a month from months vector, which is between 0 and 11.
int Date::monthIndex(const string m){
	int index;
	for(unsigned int i = 0; i < months.size(); i++){
		if(months[i] == m){
			index =  i;
			break;
		}
	}
	return index;
}

//this function is used to add n number of days to the date object
Date& Date::addDay(const int& n){
	int temp = n;

	//add days if n is positive and moves to the right of the date.	
	if(n > 0){	
		if(((day + n) > day) && ((day + n) <= daysInMonth(month, year))){
			day += n;
		}else{
			temp -= (daysInMonth(month, year) - day);
			month = nextOrPrevMonth(month, true);
			while(temp > daysInMonth(month, year)){
				if(month == "December"){
					year += 1;
				}
				temp -= daysInMonth(month, year);
				month = nextOrPrevMonth(month, true);
			}
			day = temp;
		}
	}else{ //add days if n is negative and moves to the left of the date
		int positiveTemp = abs(temp);
		if(((day + n) < day) && ((day + n) >= 1)){
			day += n;
		}else{
			positiveTemp -= day;
			month = nextOrPrevMonth(month, false);
			while(positiveTemp >= daysInMonth(month, year)){
				if(month == "January" && year == 1){
					year -= 3;
				}
				else if(month == "January"){
					year -= 1;
				}

				positiveTemp -= daysInMonth(month, year);
				month = nextOrPrevMonth(month, false);
			}
			day = daysInMonth(month, year) - positiveTemp;
		}
	}

	return *this;
}

//this function is used n number of months to the date object. if the day of month is greater than number of days in month then choose the next month with day 1
Date& Date::addMonth(const int& n){
	
	int monthInd = monthIndex(month); //to find index of month in the vector of months
	monthInd += n;
	//check if we n is positive as we need to move to the right of the date
	if(n > 0){
		while(monthInd > 11){
			monthInd -= 12;
			(year == -1) ? year = 1 : year += 1; //transition of year when year: -1 & when we add 1 to it,it should not become 0 instead the year would be 1
		}
	//check if n is negative and we need to move back from the date
 	}else if(n < 0){
		int a = monthIndex(month);
		for(int i = n; i < 0; i++){
			a = a - 1;
			if(a == 0){
				a = 12;
				year -= 1;
			}
		}
		monthInd = a;
	}

	
	month = months.at(monthInd);
	//checks if the day member of the date object is greater than the days in that month
	if(day > daysInMonth(month, year)){
		if((monthInd + 1) == 12){
			 month = months.at(0);
			 year += 1;
		}else{
			month = months.at(monthInd + 1);
		}
		day = 1;
	}
	
	return *this;
}

//this function is to used n number of years to the date object
Date& Date::addYear(const int& n){
	year  = year + n;
	if(n < 0 && year == 0){
		year = -1;
	}else if(n > 0 && year == 0){
		year += 1;
	}

	//checking the date is valid as we are adding year to it and also checking that the month of february has number of days <= to the day in dateObject	
	if(!isValidDate() && month == "February"){
		month = "March";
		day = 1;	
	}
	return *this;
}

/*this function returns returns an index value for the date object which is equal to the number of days passed from the refernce date of January 1,1
*/
int Date::dayIndex() const{
	int index = 0;
	//get the index of the day if the year is positive i.e we need to move to the right from the date.
	if(year > 0){
		for(int i = 1; i <= year; i++){
			if(i == year){
				for(unsigned j = 0; j < months.size(); j++){
					if(months[j] == month){
						index += day;
						break;
	
					}else{
						index += daysInMonth(months[j],year);
					}
				}
			}else{
				(isLeapYear(i)) ? index+= 366 : index += 365;
			}
		}
	}else{ 	//get the index of the day if year is negative ie we need to move to the left from the date.
		index = -1;
		for(int i = -1; i >= year; i--){
			if(i == year){
				for(int j = 11; j >= 0; j--){
					if(months[j] == month){
						index -= daysInMonth(months[j], year) - day;
						break;
					}else{
						index -= daysInMonth(months[j], year);
					}
				}	
			}else{
				(isLeapYear(i)) ? index -= 366 : index -= 365;
			}
		}		
	}
	return index;
}


//non- member function that returns the number of days in a month 
int getMonInd(const string m){
	int index;
	for(unsigned int i = 0; i < months.size(); i++){
		if(months[i] == m){
			index =  i;
			break;
		}
	}
	return index;
}

//non-member functin that finds the days in the month and returns it
int findDaysInMon(const string& m, const int y){
	int noOfDaysInMonth;

	if(m == "February"){
		(((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) ? noOfDaysInMonth = 29 : noOfDaysInMonth = 28;	
	}else if(m == "September" || m == "April" || m == "June" || m == "November"){
		noOfDaysInMonth = 30;
	}else{
		noOfDaysInMonth = 31;
	}

	return noOfDaysInMonth;
}

//this function gets the number of days between two given dates in the given objects.
unsigned dateDiff(const Date& d1, const Date& d2){
	int totalDays = 0;
	string MONTH = d1.getMonth();
	bool forFirstYear = true;
	int firstDay = d1.getDay();

	int firstMonthIndex = getMonInd(MONTH); //to get the month index of the first date object
	int secondMonthIndex = getMonInd(d2.getMonth()); //to get the month index of the second date object

	for(int firstYear = d1.getYear(); firstYear <= d2.getYear(); firstYear++){

		//if the year of the first Date object and the year of the second date object is equal
		if(firstYear == d2.getYear()){
			if(firstMonthIndex == secondMonthIndex){
				totalDays += d2.getDay() - firstDay;
			}else{
				totalDays += (findDaysInMon(MONTH, firstYear) - firstDay);
				firstMonthIndex += 1;
				while(firstMonthIndex != secondMonthIndex){
					totalDays += findDaysInMon(nextOrPrevMonth(MONTH, true), firstYear);
					firstMonthIndex += 1;
					MONTH = months.at(firstMonthIndex);
				}
				totalDays += d2.getDay();
			}
		}else if(firstYear == -1 && d2.getYear() == 1){
			totalDays = 1;
			break;
		}else{	//if the year of the first Date object and the year of the second date object is not equal
			if(forFirstYear){
				totalDays += (findDaysInMon(MONTH, firstYear) - firstDay);
				firstMonthIndex += 1; 
				for(int j = firstMonthIndex; j <= 11; j++){
					totalDays += findDaysInMon(nextOrPrevMonth(MONTH, true), firstYear);
					MONTH = months.at(j);
				}
				forFirstYear = false;
				firstMonthIndex = 0;
				MONTH = months.at(0);
				firstDay = 0;
			}else{
				(((firstYear % 4 == 0) && (firstYear % 100 != 0)) || (firstYear % 400 == 0)) ? totalDays += 366 : totalDays += 365;
			}
		}
	}
	return totalDays;
}

