//Main coded provided

#include <iostream>
#include <fstream>
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
	//printNames();

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
                std::cout << currentLine << std::endl;  //for testing purposes
                Student* s = new Student();
                s->init(currentLine);
                students.push_back(s);
        } // end while loop
        inFile.close();
} // end loadStudents function





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



