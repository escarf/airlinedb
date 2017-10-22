//============================================================================
// Name        : CS300Assignment2.cpp
// Author      : Me
// Date		   : 10/21/2017
// Copyright   : Your copyright notice
// Description : Sets up and maintains an airline database by handling
//				 the following commands:
//				 add, search, delete, list, quit
//============================================================================

#include <iostream>
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;

int main() {

	//OrderedLinkedList<Passenger> one = new OrderedLinkedList<Passenger>; // one of these for each flight

	OrderedLinkedList<Passenger> one; // one of these for each flight
	OrderedLinkedList<Passenger> two;
	OrderedLinkedList<Passenger> three;
	OrderedLinkedList<Passenger> four;



	bool quit = 0; // false while the user hasn't selected quit

	while(!quit) {

		char choice; // which of the options below is chosen

		cout << "***DELTA AIRLINES***" << endl;
		cout << "Please choose an operation:" << endl;
		cout <<"A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
		cout<<""<<endl;
		cin >> choice;

		if( (choice == 'A') || (choice == 'a') ) {

			int addFlight;
			string fiName;
			string laName;
			string addr;
			int phoneNum;

			bool flightOK = 0;

			bool fnameOK = 0;
			bool lnameOK = 0;


			cout<<"Enter flight number: "<< endl;
			// tests if flight number is 100, 200, 300, or 400, re-prompts until it is
			while(!flightOK) {

				cin>> addFlight;

				if(!cin.fail()) {
					flightOK = 1;

					if((addFlight == 100) || (addFlight == 200) || (addFlight == 300) || (addFlight == 400)) {
						cout<<"Flight Number Accepted"<<endl;

					}

					else {
						flightOK = 0;
					    cin.clear();
					    cin.ignore();
						cout<<"Invalid flight, try again "<<endl;
					}
				}
				else {
					cout<<"Invalid flight, try again: "<<endl;
				    cin.clear();
				    cin.ignore();

				}

				cin.clear();
				cin.ignore();
			}

			// tests if first name is valid, re-prompts until it is
			while(!fnameOK) {
				char c; // vale of c will be each char for the inputed string
				cout<<"Enter first name: "<< endl;
				cin>> fiName;

				if(!cin.fail()) {
					fnameOK = 1;

				    // check all chars in string
					for (size_t i = 0; i < fiName.length(); i++) {

				        c = fiName.at(i);

				        // this passes if c isn't a letter
				       if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ) ) {

				            fnameOK = 0;

				       }

				       else {
				       }

				    }

				    if(!fnameOK) cout<< "Invalid first name, try again" << endl;

				}
				else {
					cout<<"Invalid first name, try again: "<<endl;

				}

				cin.clear();
				cin.ignore();
			}

			// tests if last name is valid, re-prompts until it is
			while(!lnameOK) {
				char c; // vale of c will be each char for the inputed string
				cout<<"Enter last name: "<< endl;
				cin>> laName;

				if(!cin.fail()) {
					lnameOK = 1;


				    // check all chars in string
				    for (size_t i = 0; i < laName.length(); i++) {

				       c = laName.at(i);

				       // this passes if c isn't a letter
				       if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ) ) {

				            lnameOK = 0;
				       }

				       else {
				       }

				    }
				    if(!lnameOK) cout<< "Invalid last name, try again" << endl;

				}
				else {
					cout<<"Invalid last name, try again: "<<endl;

				}

				cin.clear();
				cin.ignore();
			}


			cout<<"Enter address: "<< endl;
			getline(cin, addr);


			cout<<"Enter phone number: "<< endl;
			cin>> phoneNum;

			Passenger adding(addFlight, fiName, laName, addr,  phoneNum);

			// adds in order to the correct flight
			if(addFlight == 100) {
				one.insert(adding);
			}

			else if(addFlight == 200) {
				two.insert(adding);
			}

			else if(addFlight == 300) {
				three.insert(adding);
			}

			else if(addFlight == 400) {
				four.insert(adding);
			}


			cout<<"Passenger added "<< endl;

		}

		/*
		 * searches by making a temporary passenger with first and last name
		 * input from user, and compares this temporary passenger with those of the
		 * selected flight using the == operator in OrderedLinkedList
		 */
		else if((choice == 'S') || (choice == 's')) {

			bool found = 0;
			bool fnameOK = 0;
			bool lnameOK = 0;

			string fiName;
			string laName;
			cout<<"Enter first name to search for: "<< endl;


			while(!fnameOK) {
				char c; // vale of c will be each char for the inputed string
				cout<<"Enter first name: "<< endl;
				cin>> fiName;

				if(!cin.fail()) {
					fnameOK = 1;

				    // check all chars in string
				    for (size_t i = 0; i < fiName.length(); i++) {

				        c = fiName.at(i);

				       // this passes if c isn't a letter
				       if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ) ) {

				            cout << "Invalid first name, try again" << endl;
				            fnameOK = 0;

				       }

				       else {
				       }

				    }
				    if(!fnameOK) cout<< "Invalid first name, try again" << endl;

				}
				else {
					cout<<"Invalid first name, try again: "<<endl;

				}

				cin.clear();
				cin.ignore();
			}

			while(!lnameOK) {
				char c; // vale of c will be each char for the inputed string
				cout<<"Enter last name: "<< endl;
				cin>> laName;

				if(!cin.fail()) {
					lnameOK = 1;


				    // check all chars in string
				    for (size_t i = 0; i < laName.length(); i++) {

				        c = laName.at(i);

				        // this passes if c isn't a letter
				        if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ) ) {

				             lnameOK = 0;
				        }

				        else {
				        }

				    }
				    if(!lnameOK) cout<< "Invalid last name, try again" << endl;

				}
				else {
					cout<<"Invalid last name, try again: "<<endl;

				}

				cin.clear();
				cin.ignore();
			}
			cout<<"Last name accepted"<<endl;

			Passenger search(0, fiName, laName, "", 0);


			Passenger result = one.search(search); // searching the first flight

			// if not in the first flight, searches the rest
			if(result.getFlight() == 0)

				result = two.search(search);

			if(result.getFlight() == 0)

				result = three.search(search);

			if(result.getFlight() == 0)

				result = four.search(search);

			found = 1;

			if(result.getFlight() == 0)
			{
				cout<<"Passenger not found"<<endl;
				found = 0;
			}

			if(found) {
				cout<<"Flight Number: "<< result.getFlight()<<endl;
				cout<<"First Name: "<< result.getFirst()<<endl;
				cout<<"Last Name: "<< result.getLast()<<endl;
				cout<<"Address: "<< result.getAddress()<<endl;
				cout<<"Phone Number: "<< result.getNum()<<endl;
				cout<<""<<endl;
			}

		}


		// calls OrderedLinkedList::deleting for a Passenger with the chosen last name
		else if((choice == 'D') || (choice == 'd')) {

			string laName;
			int delFlight;
			bool flightOK = 0;
			bool lnameOK = 0;


			while(!lnameOK) {
				char c; // vale of c will be each char for the inputed string
				cout<<"Enter last name: "<< endl;
				cin>> laName;

				if(!cin.fail()) {
					lnameOK = 1;


				    // check all chars in string
				    for (size_t i = 0; i < laName.length(); i++) {

				        c = laName.at(i);

				        // this passes if c isn't a letter
				        if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ) ) {

				             lnameOK = 0;
				        }

				        else {
				        }

				    }
				    if(!lnameOK) cout<< "Invalid last name, try again" << endl;

				}
				else {
					cout<<"Invalid last name, try again: "<<endl;
				}

				cin.clear();
				cin.ignore();
			}
			cout<<"Last name accepted"<<endl;

			cout<<"Enter flight number: "<< endl;

			while(!flightOK) {

				cin>> delFlight;

				if(!cin.fail()) {
					flightOK = 1;

					if((delFlight == 100) || (delFlight == 200) || (delFlight == 300) || (delFlight == 400)) {
						cout<<"Flight Number Accepted"<<endl;
					}

					else {
						flightOK = 0;
						cout<<"Invalid flight, try again: "<<endl;
					}
				}
				else {
					cout<<"Invalid flight, try again: "<<endl;
				    cin.clear();
				    cin.ignore();

				}

				cin.clear();
				cin.ignore();
			}


			Passenger deleting(delFlight, "", laName, "",  0);

			// deletes from correct flight
			if(delFlight == 100) {
				one.deleting(deleting);
			}

			else if(delFlight == 200) {
				two.deleting(deleting);
			}

			else if(delFlight == 300) {
				three.deleting(deleting);
			}

			else if(delFlight == 400) {
				four.deleting(deleting);
			}

			cout<<"Passenger deleted " << endl;

		}

		// lists all Passengers in a chosen flight
		else if((choice == 'L') || (choice == 'l')) {

			OrderedLinkedList<Passenger>* p; // points to flight specified by user

			cout<<"Enter number of flight to list: "<< endl;
			int listFlight;
			bool flightOK = 0;

			while(!flightOK) {

				cin>> listFlight;

				if(!cin.fail()) {
					flightOK = 1;

					if((listFlight == 100) || (listFlight == 200) || (listFlight == 300) || (listFlight == 400)) {
						cout<<"Flight Number Accepted"<<endl;
					}

					else {
						flightOK = 0;
						cout<<"Invalid flight, try again: "<<endl;
					}
				}
				else {
					cout<<"Invalid flight, try again: "<<endl;
				    cin.clear();
				    cin.ignore();

				}

				cin.clear();
				cin.ignore();
			}

			// lets p point to the chosen flight
			if(listFlight == 100) {

				p = &one;
			}

			else if(listFlight == 200) {
				p = &two;
			}

			else if(listFlight == 300) {
				p = &three;
			}

			else if(listFlight == 400) {
				p = &four;
			}

			cout<<"List of passengers in flight "<< listFlight <<":" << endl;

			// for loop is used to "iterate" over the list
			for(int i = 0; i < p->getCount(); i++) {

				Passenger listing(); // temporary Passenger that will have its info printed


				Passenger result = p->list(i);

				cout<<"First Name: "<< result.getFirst()<<endl;
				cout<<"Last Name: "<< result.getLast()<<endl;
				cout<<"Address: "<< result.getAddress()<<endl;
				cout<<"Phone Number: "<< result.getNum()<<endl;
				cout<<""<<endl;

			}
		}

		// user chooses to quit
		else if((choice == 'Q') || (choice == 'q')) {

			quit = 1;
		}

		else {
			cout<<"Unrecognized input: try again"<< endl;
		}

	}
	return 0;
}
