//student header

#include <string>
#include "date.h"
#include "address.h"

#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

class Student{
	private:
		std::string firstName;
		std::string lastName;
		Address* address;
		Date* birthDate;
		Date* gradDate;
		int creditHours;
	public:
		Student();
		void init(std::string studentString);
		~Student();
		void printStudent();
		std::string getLastFirst();
		std::string getLastName() const;
		std::string getFirstName() const;
		std::string getAddress() const;
		std::string getBirthDate() const;
		std::string getGradDate() const;
		int getCreditHours() const;
		friend std::ostream& operator<<(std::ostream&, const Student&);
		//bool sortByFirst(Student& a, Student& b);
		//bool sortByLast(Student& a, Student& b);
		//bool sortByCreds(Student& a, Student& b);
}; //end student class


#endif
