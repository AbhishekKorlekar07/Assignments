
/*
 * Name: Abhishek Jagannath Korlekar
 * ZID: Z1831187
 * Course: CSCI 689
 * Assignment Number: 4
 * Assignment Title: Removing comments from the source file 
 * Due Date: 10/02/17
 */

/*
 * Here in this program we are fetching the data from the input file prog4-in.cc (with comments in it), thus removing the comments from the data and 
 * copying all the data into the output file prog4-out.cc (without comments).
 * */


//importing the header file into our program what we created. Header file consists of constants and prototypes.
#include "prog4.h" 


//this function is used to close the input and outfile file what we had opened in the function open_files().
void close_files(ifstream& is, ofstream& os){
	is.close();
	os.close();
}

//this function consists of the logic to remove the comments from the data line by line and adding the line after removing the comments onto prog4-out.cc
void process_data(ifstream& is, ofstream& os){
	string text;
	int doubleSlashPos;
	int slashAsterikPos;
	bool flag = false;
	while(getline(is, text)){	
		doubleSlashPos = text.find("//");
		slashAsterikPos = text.find("/*");
		//condition to check if the line passed is still inside the comments section i.e. the line is a comment or not.
		if(flag && (text.length() != 0)){
			if(text.substr(text.length() -2) == "*/"){
				flag = false;
			}
			text = text.erase(0, text.length());			
		}
		//condition to remove comments starting from the doubleSlash i.e. //
		else if((doubleSlashPos != -1 && slashAsterikPos == -1 && text[doubleSlashPos -1] != '\"') || 
			(doubleSlashPos != -1 && (doubleSlashPos < slashAsterikPos) && text[doubleSlashPos -1] != '\"')){
	 		text = text.erase(doubleSlashPos, text.length());			
		}
		//condition to remove comments starting from the slashAsterik i.e. /*
		else if((slashAsterikPos != -1 && (slashAsterikPos < doubleSlashPos) && text[slashAsterikPos -1] != '\"') || 
			(slashAsterikPos != -1 && doubleSlashPos == -1 && text[slashAsterikPos -1] != '\"')){
			if(text.substr(text.length() -2) != "*/"){
				flag = true;
			}
			text = text.erase(slashAsterikPos, text.length());
		}	
		
		//here copying the line without any comments to the output file
		if(os.is_open()){
			os<<text<<endl;
		}
	}
}


//this function is used to open up the input and output files
void open_files(ifstream& is, ofstream& os){
	is.open(INFILE);  //opening the input file
	os.open(OUTFILE); //opening the output file
	if(is.fail() || os.fail()){  //checking for error in file
		cout<<"Error in file"<<endl;
		exit(EXIT_FAILURE);
	}
}



int main(){
	ifstream is;  //creating object for input stream
	ofstream os;  //creating object for output stream
	open_files(is, os); //calling open_files so that we can open up the files
	process_data(is, os);  //calling the process_data function for removing comments within the data
	close_files(is, os); //calling this function to close the input and output file 
	return 0;
}
