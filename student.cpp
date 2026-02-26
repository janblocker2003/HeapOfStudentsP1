//student code

#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
	firstName = "";
	lastName = "";
	//adding heap variables
	address = new Address();
	birthDate = new Date();
	gradDate = new Date();
	// these new variables are pointers^
	creditHours = 0;
} //end constructor

void Student::init(std::string studentString){
	//make a stringstream to break up the parts of the studentString
	
	std::stringstream converter;
	//std::string sFirstName;
	//std::string sLastName;
	//dont need -> can be loaded directly into parameters
	std::string sStreet;
	std::string sCity;
	std::string sState;
	std::string sZip;
	std::string sBirthDate;
	std::string sGradDate;
	std::string sCreditHours;

	//clear the converter first!
	converter.clear();
	
	//separate to temp strings made above from studentString
	converter.str(studentString);
	getline(converter, firstName, ',');
	getline(converter, lastName, ',');
	getline(converter, sStreet, ',');
	getline(converter, sCity, ',');
	getline(converter, sState, ',');
	getline(converter, sZip, ',');
	getline(converter, sBirthDate, ',');
	getline(converter, sGradDate, ',');
	getline(converter, sCreditHours);
	
	// the address data needs to go to address class!
	address->init(sStreet, sCity, sState, sZip);

	// the dates need to go to their date class! can't assign them here
	birthDate->init(sBirthDate);
	gradDate->init(sGradDate);

	//convert zip and creditHours to ints
	converter.clear();
	converter.str("");
	converter << sCreditHours;
	converter >> creditHours;

} //end initializer

Student::~Student(){
	//deleting heap variables
	delete address;
	delete birthDate;
	delete gradDate;
} //ending destructor

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	address->printAddress();
	std::cout << "Birth Date: ";
	birthDate->printDate();
	std::cout << "Grad Date: ";
	gradDate->printDate();
	std::cout << "Credits: " << creditHours << std::endl;
	std::cout << std::endl;
} //end printStudent

std::string Student::getLastFirst(){
	std::stringstream converter;
	converter.str("");
	converter << lastName << ", " << firstName;
	return converter.str();
} //getLastFirst ended

std::string Student::getLastName(){
	return lastName;
} // getLastName ended

std::string Student::getFirstName(){
	return firstName;
} // getFirstName ended

int Student::getCreditHours(){
	return creditHours;
} // getCreditHours ended


