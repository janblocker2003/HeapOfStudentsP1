//student code

#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
	firstName = "Jane";
	lastName = "Doe";
	//adding heap variables
	*Student::address = new Address();
	*Student::birthDate = new Date();
	*Student::gradDate = new Date();
	//this may also be formatted as address = new std::string(); *address = *Student::address;
	creditHours = 0;
} //end constructor

void Student::init(std::string studentString){
	//make a stringstream to break up the parts of the studentString
	
	std::stringstream converter;
	std::string sFirstName;
	std::string sLastName;
	std::string sStreet;
	std::string sCity;
	std::string sState;
	std::string sZip;
	std::string sBirthDate;
	std::string sGradDate;
	std::string sCreditHours;

	//separate to temp strings
	converter.str(studentString);
	getline(converter, sFirstName, ',');
	getline(converter, sLastName, ',');
	getline(converter, sStreet, ',');
	getline(converter, sCity, ',');
	getline(converter, sState, ',');
	getline(converter, sZip, ',');
	getline(converter, sBirthDate, ',');
	getline(converter, sGradDate, ',');
	getline(converter, sCreditHours);

	//convert zip and creditHours to ints
	converter.clear();
	converter.str("");

	converter << sFirstName << " " << sLastName << " " << sStreet << " " << sCity << " " << sState << " " << sZip << " " << sBirthDate << " " << sGradDate << " " << sCreditHours;
	converter >> firstName >> lastName >> street >> city >> state >> zip >> birthDate >> gradDate >> creditHours;
} //end initializer

~Student(){
	//deleting heap variables
	delete address;
	delete birthDate;
	delete gradDate;
} //ending destructor

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	std::cout << street << endl;
	std::cout << city << " " << state << ", " << zip << std::endl;
	std::cout << "DOB: " << birthDate << std::endl;
	std::cout << "Grad: " << gradDate << std::endl;
	std::cout << "Credits: " << creditHours << std::endl;
} //end printStudent



