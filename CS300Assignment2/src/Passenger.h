/*
 * passenger.h
 *
 *  Created on: Oct 18, 2017
 *      Author: escarf
 * Description: Passenger objects are used to represent passengers in a database storing flight information
 */
#include <iostream>
using namespace std;
class Passenger {
	int flightNum; // one of four flight numbers
	string fName; // first name
	string lName; // last name
	string address; // street address
	int num; // phone number

public:

	Passenger();
	Passenger(int flightNum, string f, string l, string address, int num);
	~Passenger();

	bool operator==(const Passenger& other) const; // no member variables of parameter object can be altered bc of outside const
	int compare(Passenger&); // uses string comparison to compare last names alphabetically

	int getFlight(); // get flight number
	string getFirst(); // get first name
	string getLast(); // get last name
	string getAddress(); // get address
	int getNum(); // get phone number

};


