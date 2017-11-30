
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 9
 * Assignment Title: A Simple Calculator
 * Due Date: 11/20/17
 */


//Here including the header file for making use of the contants and function declarations.
#include "prog9.h"

/* Checks if the character c in position i in token is a valid unary –/+ sign, which is considered
 * valid if it’s not the last character in the token and the character follows it is either
 * a digit or a decimal point.
 */
bool unarySign(const char& c, const string& token, const unsigned& i){
	return ((token[i] == '+' || token[i] == '-') && (i != token.length()-1) && (isdigit(token[i+1]) || token[i+1] == '.'));
}


/* Checks if the character c in position i in token is a valid decimal point, which is considered valid
 * if it’s not the last character in token and the character follows it is a digit.
 * */
bool floatPoint(const char& c, const string& token, const unsigned& i){
	return ((token[i] == '.') && (i != token.length() -1) && (isdigit(token[i+1])));
}


//this function is used to convert the string to double value and return the value.
double stringToDouble(string line){
	double result;
	result = stod(line);
	return result;
}

/* Here in this program getNumber function is not being used. Instead a different approach is being used.
 *
double getNumber(const char& c, const string& token, unsigned& i, const bool& floatPointFlag){
	double result;
	int decimalCount = 0;
	decimalCount = count(token.begin(), token.end(), '.');
	if(decimalCount > 1){
		cerr << "More than one decimal point values" << endl;
	}else{
		result = stringToDouble(token[i]);
	}
	return result;
}*/

/* Here process_token checks each token charachter by charachter and takes necessary actions based on the charachter value.
 *
 * */
void process_token(const string& token, stack <double>& S){
	double stringToDoubleResult = 0;
	double firstElement = 0;
	double secondElement = 0;
	double operationResult = 0;
	//loop that is used to iterated the token charachter by charachter
	for(unsigned i = 0; i < token.length(); i++){
		//creating an empty string to which all the number charachters would be appended.
		string digitVal = "";
		//if the charachter encountered is 'c'. We call the emptyStack method that empties the stack. 
		if(token[i] == 'c'){
			emptyStack(S);
		//here below we check thet the charachter is a digit or it is valid unary Sign by calling the unarySign function.
		}else if(isdigit(token[i]) || unarySign(token[i], token, i)){
			do{		
				digitVal += token[i];
				i += 1;
			}while(isdigit(token[i]) || (token[i] == '.'));
			i -= 1;

			//here below wer are counting the number of '.' in a number string, as more than one indicates that it is an invalid number 
			if(count(digitVal.begin(), digitVal.end(), '.') > 1){
				cerr << "error: number " << "'" << digitVal << "'" << " is invalid" << endl;
				break;
			}else{
				stringToDoubleResult = stringToDouble(digitVal);
				S.push(stringToDoubleResult);
			}
		/*here we are checking if the charachter is an valid operator and the next element should not be a digit. If the condition
		is true then we are popping two elements from the top of stack and performing operation on those numbers by the operator specified.
		and finally pusing the result on top of stack.
		*/
		}else if(isValidOperator(token[i]) && !isdigit(token[i + 1])){
			secondElement = popStack(S);
			firstElement = popStack(S);
			operationResult = operation(token[i], firstElement, secondElement);
			S.push(operationResult);	
		//Here we are checking if the character is an = sign. If it is then we are printing the result on stdout.
		}else if(token[i] == '='){
			printResult(S);	
		//here we are checking the if there are not any invalid charachters in the token. 
		}else if(!isalpha(token[i]) && token[i] != ' '){
			cerr << "error: character " << "'" << token[i] << "'" << " is invalid" << endl;
		}
	}
}


/*this function is used to check of the operator is an valid operator
 *  Checks if the character c is one of the four valid
 *  operators in { +, -, *, / }.
 */

bool isValidOperator(const char& c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*  Applies the operator
 *  c on the numbers x and y and returns the resulting number to the calling routine
 * */
double operation(const char& c, const double& x, const double& y){
	double result;
	if(c == '+'){
		result = x + y;
	}else if(c == '-'){
		result = x - y;
	}else if(c == '/'){
		result = x / y;
	}else if(c == '*'){
		result = x * y;
	}
	return result;
}

/* Checks if stack S is empty, and if it’s, it prints
 * out an error message on stderr to indicate the error. Otherwise, it removes and
 * returns the number at the top of S to the calling routine
 * */
double popStack(stack<double>& S){
	double topElement;
	if(S.empty()){
		cerr << "error: stack is empty" << endl;
	}else{
		topElement = S.top();
		S.pop();
	}

	return topElement;
}

/* Checks if stack S is empty, and if it’s, it
 * prints out an error message on stderr to indicate the error. Otherwise, it prints out
 * the top number in S on stdout by exactly two digits after the decimal point.
 * */
void printResult(const stack<double>& S){
	double result;
	if(S.empty()){
		cerr << "error: stack is empty" << endl;
	}else{
		result = S.top();
		cout << setw(8) << fixed << setprecision(2) << result << endl;
	}
}

/* this function is used to remove all the elements from the stack and empty it.
 *  Pops the top element from stack S and continue
 *  by popping the top element until S becomes empty.
 */

void emptyStack(stack<double>& S){
	for(unsigned i = 0; i <= S.size(); i++){
		S.pop();
	}
}


int main(){
	//defines an empty stack.
	stack<double> myStack;
	string token;
	//here we are reading input from the file line by line and passing that line to the process_token function.
	while(getline(cin, token)){
		process_token(token, myStack);			
	}
	return 0;
}

