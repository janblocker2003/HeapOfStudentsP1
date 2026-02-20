//address header

#include <string>

#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

class Address{
	private:
		std::string street;
		std::string city;
		std::string state;
		int zip;
	public:
		Address();
		void init(std::string street, std::string city, std::string state, int zip);
		void printAddress();
};


#endif
