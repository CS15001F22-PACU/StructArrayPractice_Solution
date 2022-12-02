//*********************************************************************
// File name:			main.cpp
// Author:				CS Faculty
// Date:					November 30, 2022
// Class:					CS 150-0X
// Assignment:		Struct and Array In Class Activity
// Purpose:				More practice with structs and arrays of structs
// Hours Worked:	50 minutes
//*********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

// TODO #1: Copy the struct Weather definition into main.cpp
struct Weather {
	double highTemp;
	double lowTemp;
	double rainInInches;
	double snowInInches;
};


// TODO #4a: Write the printWeather function prototype
void printWeather (const Weather& sWeather);

// TODO #5a: Write the printAllWeather function prototype
void printAllWeather (const Weather[], int size);

// TODO #8a: Write the hottestDay function prototype
int hottestDay (const Weather[], int size);

// TODO #10a: Write the biggestChange function prototype
int biggestChange (const Weather[], int size);


// TODO 14a (BONUS): Write the writeWeather function protype
void writeWeather (const Weather sDays[], int size);

// TODO 15a (BONUS): Write the readWeather function protype
void readWeather (Weather sDays[], int &size);


//*********************************************************************
// Function:		main
//
// Description:	practice with structs and arrays
// 
// Parameters:	NONE
//
// Returned:		EXIT_SUCCESS
//*********************************************************************
int main (){
	const int MAX_DAYS = 31;
	// TODO #2: Delcare an array of 31 Weather structs in main ()
	Weather sDays[MAX_DAYS];
	int numElems;

	// TODO #3: Fill in first 7 array positions with the given data
	sDays[0] = { 45, 33, 0, 0 };
	sDays[1] = { 35, 21, 0.5, 0 };
	sDays[2] = { 32, 27, 0, 1.1 };
	sDays[3] = { 33, 22, 0, 0.1 };
	sDays[4] = { 41, 29, 0.25, 0 };
	sDays[5] = { 45, 22, 0, 0 };
	sDays[6] = { 49, 34, 0.75, 0 };

	numElems = 7;

	// TODO #6: In main, print the weather in array positions 0, 1, 2. 
	cout << "Days 0-2" << endl;
	for (int i = 0; i < 3; i++) {
		printWeather (sDays[i]);
		cout << endl;
	}

	// TODO #7: In main, print the weather in all the array positions
	cout << "All Weather" << endl;
	printAllWeather (sDays, numElems);
	cout << endl;

	// TODO #9: In main, print the weather on the hottest day
	cout << "Hottest Day" << endl;
	printWeather (sDays[hottestDay (sDays, numElems)]);
	cout << endl;

	// TODO #11: In main, print the weather on the day with the biggest change
	cout << "Biggest Change" << endl;
	printWeather (sDays[biggestChange (sDays, numElems)]);
	cout << endl;

	// TODO #12: In main, add the weather {30.0, 20.0, 0.0, 14.0} in 
	//					 position 0 of the array and shift the existing items 
	//					 in the array one slot to make room
	for (int i = numElems - 1;  i >=0; i--) {
		sDays[i + 1] = sDays[i];
	}
	sDays[0] = { 30.0, 20.0, 0.0, 14.0 };
	numElems++;

	// TODO #13: In main, print the weather in all the array positions
	cout << "All Weather" << endl;
	printAllWeather (sDays, numElems);
	cout << endl;

	writeWeather (sDays, numElems);
	
	
	// blank out all the data in the array to
	// test that file reading works correctly
	for (int i = 0; i < numElems; i++)
	{
		sDays[i] = { 0,0,0,0 };
	}
	cout << "All Weather Before Read From File" << endl;
	printAllWeather (sDays, numElems);
	cout << endl;

	readWeather (sDays, numElems);
	cout << "All Weather After Read From File" << endl;
	printAllWeather (sDays, numElems);
	cout << endl;

	return EXIT_SUCCESS;
}

// TODO #4b: Write the function printWeather which will print one 
//					 Weather structure

//*********************************************************************
// Function:		printWeather
//
// Description:	Print an individual Weather struct
// 
// Parameters:	sDay - the struct to print
//
// Returned:		none
//*********************************************************************
void printWeather (const Weather& sDay) {
	cout << "H: " << sDay.highTemp;
	cout << " L: " << sDay.lowTemp;
	cout << " R: " << sDay.rainInInches;
	cout << " S: " << sDay.snowInInches;
}


// TODO #5b: Write the printAllWeather function which will print every
//					 Weather struct in an array

//*********************************************************************
// Function:		printAllWeather
//
// Description:	Print each Weather struct in an array
// 
// Parameters:	sDays - the array of Weather structs
//							size	- the number of items in the array
//
// Returned:		none
//*********************************************************************
void printAllWeather (const Weather sDays[], int size) {
	for (int i = 0; i < size; i++) {
		printWeather (sDays[i]);
		cout << endl;
	}
}


// TODO #8b: Write the hottestDay function which will find the day with
//           the highest high temperature and return the index of that 
//           day in the array

//*********************************************************************
// Function:		hottestDay
//
// Description:	Determine the hottest day in the array
// 
// Parameters:	sDays - the array of Weather structs
//							size	- the number of items in the array
//
// Returned:		the index of the hottest day in the array
//*********************************************************************
int hottestDay (const Weather sDays[], int size) {
	int retVal = 0;
	for (int i = 0; i < size; i++) {
		if (sDays[i].highTemp > sDays[retVal].highTemp) {
			retVal = i;
		}
	}
	return retVal;
}


// TODO #10b: Write the biggestChange function which will find the day
//						with the biggest difference between the high and low
//						temperature and return the index of the day in the array.

//*********************************************************************
// Function:		biggestChange
//
// Description:	Determine the day with the biggest temperature change
// 
// Parameters:	sDays - the array of Weather structs
//							size	- the number of items in the array
//
// Returned:		the index of the day with biggest temperature change
//*********************************************************************
int biggestChange (const Weather sDays[], int size) {
	int retVal = 0;
	for (int i = 0; i < size; i++) {
		if ( (sDays[i].highTemp - sDays[i].lowTemp) > 
			(sDays[retVal].highTemp - sDays[retVal].lowTemp) ) {
			retVal = i;
		}
	}

	return retVal;
}





// TODO #14b: Write the writeWeather function definition

//*********************************************************************
// Function:		writeWeather
//
// Description:	Write the array of structs to a file
// 
// Parameters:	sDays - the array of Weather structs
//							size	- the number of items in the array
// 
// Returned:		none
//*********************************************************************
void writeWeather (const Weather sDays[], int size) {
	ofstream outFile;

	outFile.open ("data.txt");
	if (outFile.fail ()) {
		cout << "Cannot open data.txt" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		outFile << sDays[i].highTemp;
		outFile << " " << sDays[i].lowTemp;
		outFile << " " << sDays[i].rainInInches;
		outFile << " " << sDays[i].snowInInches;
		outFile << endl;
	}
	outFile.close ();

}


// TODO #15b: Write the readWeather function definition

//*********************************************************************
// Function:		readWeather
//
// Description:	Read Weather structs from a file into an array
// 
// Parameters:	sDays - the array of Weather structs
//							size	- the number of items in the array after
//											reading data from the file
// 
// Returned:		none
//*********************************************************************
void readWeather (Weather sDays[], int &size) {
	ifstream inFile;
	
	size = 0;

	inFile.open ("data.txt");
	if (inFile.fail ()) {
		cout << "Cannot open data.txt" << endl;
		return;
	}
	
	while (inFile >> sDays[size].highTemp) {
		inFile >> sDays[size].lowTemp;
		inFile >> sDays[size].rainInInches;
		inFile >> sDays[size].snowInInches;
		size++;
	}

	inFile.close ();
}
