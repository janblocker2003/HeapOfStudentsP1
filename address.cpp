// address code

#include <iostream>
#include <sstream>
#include "address.h"

Address::Address(){
	street = "";
	city = "";
	state = "";
	zip = 0;
} //end constructor

void Address::init(std::string street, std::string city, std::string state, std::string sZip){
	//normal initializations
	Address::street = street;
	Address::city = city;
	Address::state = state;
	
	//make stringstream and convert to int
	std::stringstream converter;
	converter << sZip;
	converter >> Address::zip;

} // end initializer

void Address::printAddress(){
	std::cout << street << ", " << city << ", " << state << " " << zip << std::endl;
} //end printAddress
