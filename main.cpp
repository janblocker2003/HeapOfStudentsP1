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
	//printNames(students);
	//printDetails(students);
	search(students);
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
		//std::cout << student->init(student->Address* Student::address) std::endl;
		//std::cout << address->Address::printAddress() << std::endl; 
		//std::cout << student->init(student*) << Address::printAddress() << std::endl;
		//std::cout << "DOB: " << student->Date::printDate() << std::endl;
		//std::cout << "Grad: " << student->init(student*) << Date::printDate() << std::endl;
		std::cout << "Credits: " << student->getCreditHours() << std::endl;
		std::cout << "__________________________________________________________" << std::endl;
	} //end for loop
	std::cout << std::endl << std::endl;
} //end printDetails function

void search(std::vector<Student*>& students){
	std::string userName;
	std::cout << "Last name of student: ";
  	std::cin >> userName;
	for (Student* student: students){
		std::stringstream converter;
		converter << static_cast<void*>(student);
		std::string copyStudent = converter.str();
		//std::string copyStudent = std::to_string(student->id);
		std::size_t found = copyStudent.find(userName);
		if (found!=std::string::npos){
			//std::vector<Student*> newStew;
			Student* s = new Student();
			//newStew = student;
			std::cout << copyStudent << std::endl; //testing
			s->init(copyStudent);
        		s->printStudent();
			//printDetails(newStew);
		} //end if
		else{
			std::cout << "didn't find: " << copyStudent << std::endl; //tester
		} //end else
	} // end for
} //end search

std::string menu();



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



