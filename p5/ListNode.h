#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

class ListNode {
	
public:
	ListNode() {
        cout  << "In  ListNode Constructor..." << endl;
		next = nullptr;
	}
	
	~ListNode() {
	    cout  << "In  ListNode Destructor..." << endl;
	}
	
    int getValue() {
        return value;
    }
    void setValue(Car carValue) {
        this->value = value;
    }
    
	ListNode* getNext() {
        return next;
    }
	void setNext(ListNode * next) {
        this->next = next;
    }

private:
    int value;
    ListNode *next;
};

#endif
