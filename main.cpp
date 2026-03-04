//Main coded provided

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "date.h"
#include "address.h"
#include "student.h"
#include <vector>
#include <algorithm>
#include <random>
#include <map>

void testAddress();
void testDate();
void testStudent();

void loadStudents(std::vector<Student*>&);
void printNames(std::vector<Student*>&);
void printDetails(std::vector<Student*>&);
void search(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();


int main(){
	std::vector<Student*> students;
	loadStudents(students);
	std::string response = "";
	bool keepGoing = true;
	while (keepGoing == true){
		response = menu();
		if (response == std::to_string(0)) {
			keepGoing = false;
		} //end 0 if
		else if (response == std::to_string(1)) {
			printNames(students);
		} // end 1 if
		else if (response == std::to_string(2)) {
			printDetails(students);
		} // end 2 if
		else if (response == std::to_string(3)) {
			search(students);
		} // end 3 if
	} //end while
	delStudents(students);

	/*
	std::cout << "Hello!" << std::endl;
	testAddress();
	testDate();
	testStudent();

	*/
	return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
	std::ifstream inFile;
        std::string currentLine;
        inFile.open("students.csv");
        while(getline(inFile, currentLine)){
                //std::cout << currentLine << std::endl;  //for testing purposes
                Student* s = new Student();
                s->init(currentLine);
                students.push_back(s);
        } // end while loop
        inFile.close();
} // end loadStudents function

void printNames(std::vector<Student*>& students){
	for (Student* student: students){
		std::cout << student->getLastFirst();
		std::cout << ", " << student->getCreditHours() << std::endl;
	} // end for loop

} // end printNames function

void delStudents(std::vector<Student*>& students){
	for (Student* student: students){
		delete student;
	} // end for loop
} // end delStudents function

void printDetails(std::vector<Student*>& students){
	for (Student* student: students){
		std::cout << student->getFirstName() << " " << student->getLastName() << std::endl;
		std::cout << student->getAddress() << std::endl;
		std::cout << "DOB: " << student->getBirthDate() << std::endl;
		std::cout << "Grad: " << student->getGradDate() << std::endl;
		std::cout << "Credits: " << student->getCreditHours() << std::endl;
		std::cout << "__________________________________________________________" << std::endl;
	} //end for loop
	std::cout << std::endl << std::endl;
} //end printDetails function

void search(std::vector<Student*>& students){
	std::string userName;
	std::cout << "Last name of student: ";
  	std::cin >> userName;
	std::cout << std::endl << std::endl;
	for (Student* student: students){
		std::stringstream converter;
		converter << *student;
		std::string copyStudent = converter.str();
		std::size_t found = copyStudent.find(userName);
		if (found!=std::string::npos){
			Student* s = new Student();
			s->init(copyStudent);
        		s->printStudent();
		} //end if
	} // end for
} //end search

std::string menu(){
	std::map<std::string, std::string> menuOptions;
	std::string input = "";
	menuOptions["0"] = "quit";
	menuOptions["1"] = "print all student names";
	menuOptions["2"] = "print all student data";
	menuOptions["3"] = "find a student";
	std::cout << std::endl << std::endl;
	for (const auto& option : menuOptions) {
		std::cout << option.first << ": " << option.second << std::endl;
	} //end for
	std::cout << std::endl << std::endl << "Please choose 0-3: ";
	std::cin >> input;
	return input;
} //end menu


///TESTERS!!!!!!
void testAddress(){
	Address a;
	a.init("123 W Main St", "Muncie", "IN", "47303");
	a.printAddress();
} // end testAddress

void testDate(){	
	Date d;
	d.init("01/27/1997");
	d.printDate();
} // end testDate

void testStudent(){
	std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
	Student* student = new Student();
	student->init(studentString);
	student->printStudent();
	std::cout << std::endl;
	std::cout << student->getLastFirst();
	delete student;
} // end testStudent



