#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H 1

#include <iostream>
#include "LinkedStackMember.h"
#include "LinkedStackMemento.h"

using namespace std;

class LinkedStackIterator;

class LinkedStack
{
    friend class LinkedStackMemento;
    friend class LinkedStackIterator;
private:
    LinkedStackNode head;
public:
    LinkedStack()
        : head( 0 )
    {
    }

    ~LinkedStack()
    {
        LinkedStackNode temp;
        for ( LinkedStackNode p = head; p != 0; )
        {
            temp = p;
            p = p->next;
            delete temp;
        }
    }

    LinkedStackMemento* createMemento();

    LinkedStackIterator* createIterator();

    bool isEmpty()
    {
        return head == 0;
    }

    void print( ostream & out )
    {
        for ( LinkedStackNode p = head; p != 0; p = p->next )
        {
            out << p->value << ' ';
        }
    }

    char pop()
    {
        char c = head->value;
        LinkedStackNode p = head;
        head = head->next;
        delete p;
        return c;
    }

    void push( char c )
    {
        head = new LinkedStackMember( c, head );
    }

    void restore(LinkedStackMemento* m)
    {
        m->restore(this);
    }

    int size()
    {
        int len = 0;
        for ( LinkedStackNode p = head; p != 0; p = p->next )
        {
            ++len;
        }
        return len;
    }
};

#endif
