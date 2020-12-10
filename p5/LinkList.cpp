#include "LinkList.h"
#include <iostream>

using namespace std;

LinkList::LinkList() {
    cout << "In the LinkList Constructor..." << endl;
    
	head = nullptr;
    size = 0;
}

LinkList::~LinkList() {
    cout << "In the LinkList Destructor..." << endl;
    
    while(!is_empty()) {
        remove(0);
    }
}

bool LinkList::is_empty() {
    return size == 0;
}

int LinkList::getSize() {
    return size;
}

ListNode * LinkList::at(int index) {
    ListNode * current = head;
    
    for(int i = 0; i < index; i++) {
        current = current->getNext();
    }
    
    return current;
}

void LinkList::remove(int index) {
    ListNode * current;
    ListNode * previous;

    if (index == 0) {
        current = at(0);
        head = current->getNext();
        delete current;
    } else {
        previous = at(index - 1);
        current = previous->getNext();
        previous->setNext(current->getNext());
        delete current;
    }
    size--;
}

void LinkList::add(ListNode * newNode) {
    if (is_empty()) {
        head = newNode;
    } else {
        // go to just before the end of the list
        ListNode * current = at(size - 1);
        current->setNext(newNode);
    }
    size++;
}
     

