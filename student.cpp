//student code

#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
	firstName = "Jane";
	lastName = "Doe";
	Student::address = Address();
	Student::birthDate = Date();
	Student::gradDate = Date();
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

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	std::cout << street << endl;
	std::cout << city << " " << state << ", " << zip << std::endl;
	std::cout << "DOB: " << birthDate << std::endl;
	std::cout << "Grad: " << gradDate << std::endl;
	std::cout << "Credits: " << creditHours << std::endl;
} //end printStudent



