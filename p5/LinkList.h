#ifndef LINKLIST_H
#define LINKLIST_H

#include "ListNode.h"
#include <string>

class LinkList {
	
public:
	LinkList();
	~LinkList();
	
    int getSize();
    bool is_empty();
    ListNode * at(int);
	void add(ListNode *);
	void display();
	void remove(int);
    
private:
	ListNode * head;
    int size;
};

#endif
