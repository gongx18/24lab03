// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node *cur = source.first; 
 
    while(cur != NULL){
        append(cur->info);                             //append to what?
        cur = cur->next; 
    }
}

// destructor deletes all nodes
IntList::~IntList() {
 	Node* hptr = first;
        Node* temp;   
 	while(hptr){
 		temp = hptr->next; 
 		delete(hptr);
 		hptr = temp; 
 	}
 	hptr = 0;  
}


// return sum of values in list
int IntList::sum() const {
     	int sum = 0; 
	Node *cur = first; 
	while(cur != NULL){
		sum += cur -> info; 
		cur = cur -> next; 
	}
	return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
 	Node *cur = first;
 	while(cur != NULL){
 		if(cur->info == value){
 			return true; 
 		}
 		else{
 			cur = cur->next; 
 		}
	}
	return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* cur = first;
    if(cur == NULL) return 0;  
	int max = first->info; 
	while(cur != NULL){
		max = (cur->info > max ? cur->info : max);
		cur = cur->next;  
	}
	return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
     	double sum = 0; 
 	double count = 0;
	Node *cur = first; 
	if(cur == NULL) return 0.0; 
	while(cur != NULL){
		sum += cur -> info; 
		cur = cur -> next; 
		count ++; 
	}
	return sum/count;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
 	Node *temp = new Node; 
	temp -> info = value; 
	temp -> next = first; 
	first = temp; 
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
