
/*
 * Here in this program we are calculating the value of pi using the formula specified by mathematician Leibniz. 
 * */


//including the header file what we have created.
#include "prog1.h"


/*this function would get user input and it would perform number of iterations specified by the user as
per the formula specified by mathematician Leibniz and return the result*/
double add_terms(int val){
	int n = 3;
	double x = 1;
	bool flag = true;

	/*this loop runs till the number of iterations specified by the user. It goes on adding and subtracting fractions
	alternatively by incrementing the value of the denominator of the fraction by two*/ 
	for(int i = 1; i < val; i++){
		if(flag){
			x = x - ((double)1 / (double)n);
		}else{
			x = x + ((double)1 / (double)n);
		}
		flag = !flag;
		n = n + 2;
	}
	return 4 * x; //here four is multiplied as we need to get the value of pi, thus moving it to the right hand side.
}

int main(){
	int num = 0;
	//getting input value from the user.
	cout<<"Please enter a number: "<<endl;
	cin>>num;

	//check to validate the user input is in the range.
	if(num > 0){
		//calling the subroutine and passing the user input to the it and thus storing the result of the subroutine into a variable.
		double result = add_terms(num);
		cout<<"final result is: "<<result<<endl;
	}else{
		cout<<"Not a valid input"<<endl;
	}
}
