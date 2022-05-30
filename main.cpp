/*This program is an example of using MATLAB generated lib/dll in C++ environment
 *It reads a data file that has five columns of numeric data, and the dll will calculate the mean of each line of the data file
 * learn more about MATLAB mwarray api at 
 * https://www.mathworks.com/help/compiler_sdk/cxx/mwarray.html; https://www.mathworks.com/help/compiler_sdk/cxx_mwArray_API_shared_library.html
*/

#include "avgFuncLib.h"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <sstream>
#include <windows.h>

const int N = 5;
const int speed = 500; //The "sleep time" after each calculation, in milliseconds. 0.5sec by default

int main() {


	/*Loading Libraries. Set up application state shared by all MATLAB Runtime instances*/
	if (!mclInitializeApplication(NULL, 0)) {
		std::cerr << "could not initialize the application properly" << std::endl;
		std::cin.get();
		return -1;
	}

	if (!avgFuncLibInitialize()) {
		std::cerr << "could not initialize the library properly" << std::endl;
		std::cin.get();
		return -1;
	}
	
	/*Test the code without reading data from a file
	double data[5] = {1.7,3.5,5.1,7.79,9};
	mwArray a(1, 5, mxDOUBLE_CLASS);
	a.SetData(data, 5); 
	mwArray outp;
	avgFunc(1, outp, a); 
	mxDouble result;
	outp.GetData(&result, 1); 
	std::cout << "The average is: " << result << std::endl;
	std::cin.get();
	*/

	/*Open file*/
	std::ifstream inFile("mydata.txt");
	if (!inFile) {
		std::cout << "Couldn't open the file" << std::endl;
		exit(1);
	}

	/*1. Save each line of the file into an string array then convert it to a double array.
	 *2. Call the avgFunc function in the MATLAB library then output the result*/

	std::string line;
	std::string strDataArr[N];
	double numDataArr[N]={0.00,0.00,0.00,0.00,0.00};
	while (getline(inFile, line)) {
		
		std::stringstream str(line);

		int i = 0;
		while (str.good() && i < N) {
			str >> strDataArr[i];
			numDataArr[i] = stod(strDataArr[i]);
			++i;
		}
		mwArray d(1, N, mxDOUBLE_CLASS); //create a 1*N array buffer
		d.SetData(numDataArr, N);//set data into the buffer
		mwArray out;
		avgFunc(1, out, d); //MATLAB Function call. 1 means one output

		mxDouble result;
		out.GetData(&result, 1); //store output data into a buffer, result. 1 is the length of this buffer, as a single number.
		std::cout << "=============================================================" << std::endl;
		std::cout << line << std::endl;
		std::cout << std::fixed;
		std::cout << "Average: " << std::setprecision(4)<< result << std::endl;
		
		Sleep(speed);
	}

	std::cin.get();


	
	/*Termination*/
	avgFuncLibTerminate();
	if (!mclTerminateApplication()) {
		std::cerr << "Unexpected error during termination" << std::endl;
		std::cin.get();
		return -1;
	}

	return 0;
}



