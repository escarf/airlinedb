/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 18, 2017
 *      Author: escarf
 * Description: Inherits from LinkedList class,with functions added to maintain an ordered list
 *
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include "LinkedList.h"
using namespace std;
template <class T>

class OrderedLinkedList: public LinkedList<T> {
public:
		OrderedLinkedList(); // constructor
		void insert(T&); // adds a new object to list while keeping list sorted
		T search(T&); // returns an object with data matching that of the object passed in
		void deleting(T&); // deletes an object with data matching that of the object passed in
		void operator delete(void*); // deletes object that a node is pointing to
		T list(int); // int parameter is used iteration (e.g.: first object is returned when 0 is passed)
		int getCount(); // returns count
		~OrderedLinkedList(){}; // destructor

};

template <class T>
OrderedLinkedList<T>::OrderedLinkedList() {
}


template <class T>
void OrderedLinkedList<T>::insert(T& item) {

	node<T> *adding = new node<T>; // points to object being added
	adding->data = item;

	node<T>* p = this->head;
	node<T>* q = p;

	// empty list
	if(this->isEmpty()) {
		this->insertFirst(item);
	}

	// list only has one object
	else if(this->head->next == NULL) {

		// if the last name of item is earlier in alphabet than the one object in list
		if(adding->data.compare(this->head->data) < 0) {
			this->insertFirst(item);
		}

		// last name is later or the same
		else {
			this->insertLast(item);
		}

	}

	// list has more than 1 object
	else {

		// if the last name of item is earlier in alphabet or the same as that of head
		if(adding->data.compare(this->head->data) < 0 || adding->data.compare(this->head->data) == 0) {
			this->insertFirst(item);
		}

		// if the last name should be later
		else if(adding->data.compare(this->head->data) > 0) {

			do {
					p = q;
					q = q->next;

					// reached the end, insert last
					if(q->next == NULL && adding->data.compare(q->data) > 0) {
						this->insertLast(item);
					}

					// item should be inserted but not last
					else if(adding->data.compare(q->data) < 0 ) {
						p->next = adding;
						adding->next = q;
						this->count++;
					}
			}
			while(adding->data.compare(q->data) < 0 && q->next!=NULL);

		}

	}

}

// returns the input object if not found
// (the input object should have values that make it distinguishable from an "actual" Passenger)
template <class T>
T OrderedLinkedList<T>::search(T& item) {
	node<T>* p = this->head;

	if(p->data == item) {
		return p->data;
	}

	while(p->next != NULL) {

		p = p->next;

		if(p->data == item) {
			return p->data;
		}

	}

	return item;

}

// deletes the node in the list that has data matching the object passed as parameter
template <class T>
void OrderedLinkedList<T>::deleting(T& item){
	node<T>* del = new node<T>;
	del->data = item;

	node<T>* p = this->head;
	node<T>* q = p;

	// head points to node that will be deleted
	if(del->data.compare(p->data) == 0) {

		this->head = p->next;
		delete p;
		delete del;
		this->count--;
		return;
	}

	while(p->next != NULL) {

		q = p;
		p = p->next;

		// found the one to delete
		if(del->data.compare(p->data) == 0 ) {

			// deleting last object, so there is no p->next
			if(p->next== NULL) {
				delete p;
				q->next = NULL;
				this->last = q;
				this->count--;
			}

			// deleting an object that isn't last
			else {
				q->next = p->next;
				delete p;
				this->count--;
			}

			delete del;
			return;
		}

	}
}

// overloads delete operator
template <class T>
void OrderedLinkedList<T>::operator delete(void * p)
{
    free(p);
}


// int parameter is used iteration (e.g.: first object is returned when 0 is passed)
// returns the data of the ith item in list
template <class T>
T OrderedLinkedList<T>::list(int i) {
	node<T>* p = this->head;
	int k = 0; // for counting

	// if listing first one first one
	if ( k == i ) {
		return p->data;
	}

	// if listing any after the first one
	// this increments k and and advances p simultaneously until k==i
	while(k<i) {
		k++;
		p = p->next;

	}

	return p->data;
}
template <class T>
int OrderedLinkedList<T>::getCount() {
	return this->count;
}

#endif /* ORDEREDLINKEDLIST_H_ */
