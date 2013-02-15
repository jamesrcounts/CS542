#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include "CharLinkedList.h"

class LinkedStack
{
private:
	CharLinkedList head;
public:
	LinkedStack(): head(0)
	{
	}

	void push(char c);
	char pop();
	void print(ostream & out)
	~LinkedStack();
};
#endif

