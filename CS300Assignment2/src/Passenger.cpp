/*
 * Passenger.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: escarf
 *
 */

#include "Passenger.h"
#include <iostream>
using namespace std;

Passenger::Passenger() {

	Passenger:: flightNum = 0;
	Passenger:: fName = "none";
	Passenger:: lName = "none";
	Passenger:: address = "none";
	Passenger:: num = 0;
}
Passenger::Passenger(int flightNum, string f, string l, string address, int num) {

	Passenger:: flightNum = flightNum;
	Passenger:: fName = f;
	Passenger:: lName = l;
	Passenger:: address = address;
	Passenger:: num = num;

}

Passenger::~Passenger() {
}

// compares Passengers by first and last name
bool Passenger::operator==(const Passenger& other) const {
	return ( (fName == other.fName) && (lName == other.lName) );
}


// compare by last name
int Passenger::compare(Passenger &pas2) {
	return ( (getLast()).compare(pas2.getLast()) );
}


// get flight number
int Passenger::getFlight() {
	return this->flightNum;
}

// get first name
string Passenger::getFirst() {
	return this->fName;

}

// get last name
string Passenger::getLast() {
	return this->lName;
}

// get address
string Passenger::getAddress() {
	return this->address;
}

// get phone number
int Passenger::getNum() {
	return this->num;
}
