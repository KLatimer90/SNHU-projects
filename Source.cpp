/*
*CS 210 Programming Languages
*Project 3 Module 7
*Author: Kyle Latimer
*Date: 2/22/2022
*
*Program Description:
*This program will ask the end user for input. If the end user chooses option 1, the program will open a 
*file, file CS210_Project_Three_Input_File.txt, will read the file, and will create file frequency.dat. 
*The information will then be soted and alphabatized in a list. The C++ Source code will then output the
*data for the end user. 
*
*If the user chooses option 2, the program will then ask the user what item they would like to be displayed. 
*The user will then input an item. The program will then convert the input to a capitalized string, so case 
*does not affect the output. The program will then output the freequency that specified item. 
*
*If the user chooses option 3, the program will utput a histogram of each item and it's frequency for the 
*user.
*
*If the user inputs option 4, the program will finish and exit. */

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>


//C210 Starter CPP: Provided Source Code for Python/C++.
using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

void menuFunction() {


	//Prints menu options for user. 
	cout << "*******************************************************************************" << endl;
	cout << "**********************************Main Menu************************************" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*Enter your selection as a number 1, 2, 3 or 4.                               *" << endl;
	cout << "*1: Outputs a list of items purchased and the quantity of that item purchased.*" << endl;
	cout << "*2: Outputs number of items purchased for a specified item.                   *" << endl;
	cout << "*3: Outputs a histogram of each item and quantity purchases.                  *" << endl;
	cout << "*4: Exit program.                                                             *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
	cout << "Enter selection" << endl;

}

//Main function
int main()
{

	//Main function loop. Iterates until user ends program with response of 3. 
	//Also ensures user enters correct input. 
	char answer;

	//Calls menu function and asks user for input. user input assigned to char variable "answer".

	menuFunction();
	
	cin >> answer;

	while (answer != '-4')
	{
	
		if(answer == '1'){
//Answer choice 1 prints statement and then calls read_File function from .PY file. 
//Function will output item type and number of specified items once called.


			cout << endl;
			cout << "*******************************************************************************" << endl;
			cout << "*                           Total Purchased Today                             *" << endl;
			cout << "*******************************************************************************" << endl;
			

			CallProcedure("read_File");
			//CS210_Starter_PY_Code.PY Function reads CS210_Project_Three_Input_File.txt file, configures 
			//list and amounts of specified item and prints list for user.
			menuFunction();
			cin >> answer;


		}
		if (answer == '2') {

			// If answer is 2, program will prompt user for an item choice to be looked up. in the 
			//data in CS210_Project_Three_Input_File.txt. Program will call on CS210_Starter_PY_Code.py 
			//function locate_Total_Product_Amount and will out put statement and number of specified item.

			string userItem;
			cout << "*******************************************************************************" << endl;
			cout << endl;
			cout << "Please Enter the Product you wish to look up:                                " << endl;
			
			std::cin >> userItem;
			
			//This loop converts userItem into capitilized string so user input not case sensitive. 
			
			string userItemTemp = userItem;
			for (int i = 0; i < userItemTemp.size(); i++) {
				int c = userItemTemp[i];
				if (islower(c))
					userItemTemp[i] = toupper(c);
				}
			
			userItem = userItemTemp;
			
			//cout << userItem; test output, ensures capitalized string.
			 
			//obtains user input: item for quantity to be searched.

			int totalNum = callIntFunc("locate_Total_Product_Amount", userItem); //Obtains number of item that user input.

			if (totalNum == -1) {
				cout << "*******************************************************************************" << endl;
				cout << "*                                                                             *" << endl;
				cout << "*Item not found, please try again.                                            *" << endl;
				cout << "*                                                                             *" << endl;
				cout << "*******************************************************************************" << endl;
				// Verifies item is in CS210_Project_Three_Input_File.txt, 
				//prompts user for another input.
			}
			else {
				//This block enables correct output spacing to compensate for number of characters in a sting.
				string convertIntStr = to_string(totalNum);
				int totalNumNum = convertIntStr.length();
				int userItemNum = userItem.length();

				cout << "*******************************************************************************" << endl;
				cout << "*                                                                             *" << endl;
				cout << "*Total of " << totalNum << " " << userItem << " sold today." 
					<< setw(56 - totalNumNum - userItemNum) << "*" << endl; 
				cout << "*                                                                             *" << endl;
				//Prints item total.
				//Prompts another command from main menu.
				menuFunction();
				cin >> answer;

				}
			}

			if (answer == '3') {

			// Calls python function read_AND_Write_File Function reads CS210_Project_Three_Input_File.txt.
			// and writes it to frequency.dat. Function then reads frequency.dat and creates Histogram 
			// outputting items and frequency for user.


			CallProcedure("read_AND_Write_File");
			menuFunction();
			cin >> answer;


		}
			//Ends program. 
			if (answer == '4') {
				cout << "Program Finished.";
				answer == '-4';
				return 0;

			}
						
			//Validation section of loop.
			if ((answer != '1') && (answer != '2') && (answer != '3') && (answer != '4')) {
				cout << "Invalid Entry, please enter 1, 2, 3, or 4." << endl;
				cin >> answer;

			}

	}
	return 0;
}
