//date header

#include <string>

#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

class Date{
	private:
		int month;
		int day;
		int year;
		std::string monthArray[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	public:
		Date();
		void init(std::string dateString);
		void printDate();
};


#endif
