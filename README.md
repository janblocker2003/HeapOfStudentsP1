# Heap of Students Documentation

## UML diagram

```mermaid
classDiagram
direction TB
    class Address {
	    - string street
	    - string city
	    - string state
	    - int zip
	    + Address()
	    + init(street, city, state, zip)
	    + void printAddress()
    }

    class Date {
	    - int Month
        - int Day
	    - int Year
	    + Date()
	    + init(dateString)
	    + void printDate()
    }

    class Student {
	    - string firstName
	    - string lastName
        - pointer Address: address
	    - pointer Date: birthDate
	    - pointer Date: gradDate
	    - int creditHours
	    + Student()
	    + init(string studentString)
		+ ~Student() destructor
	    + void printStudent()
	    + void getLastFirst() return string
    }

    Address <|-- Student
    Date <|-- Student
```

## Rest of Algorithm

## Finished make file should be:

'''
//make file

program: main.o student.o date.o address.o
        g++ -g main.o student.o date.o address.o -o program

main.o: main.cpp student.h date.h address.h
        g++ -g -c main.cpp

student.o: student.h date.h address.h student.cpp
        g++ -g -c student.cpp

date.o: date.h date.cpp
        g++ -g -c date.cpp

address.o: address.h address.cpp
        g++ -g -c address.cpp

clean:
        rm program
        rm *.o

run: program
        ./program

debug: program
        gdb program

valgrind: program
        valgrind --leakcheck=full ./program
~                                                    
'''

In date() 
add an array of 13 string values starting with null as 0 so that jan = 1 etc.

Address takes in 4 strings and prints them out

# New main notes from teacher!!!!

1. should open the students.csv file
2. shoudl create a vector of student pointers
3. should load each student from a line of all the students
4. present a menu to the user
   - quit
   - print the names of all the students
   - print details of all the students
   - search for a student
5. the user should be able to choose from at least those three options
6. when user quits:
   - the program cleans up the vector (vector will be on the heap)
   - close the student file
   - exit




