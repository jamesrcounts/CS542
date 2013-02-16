#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "CharLinkedListPair.h"

using namespace std;

class LinkedStack
{
private:
    CharLinkedList head;
public:
    LinkedStack() : head ( 0 )
    {
    }

    ~LinkedStack()
    {
        CharLinkedList temp;
        for ( CharLinkedList p = head; p != 0; )
        {
            temp = p;
            p = p->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return head == 0;
    }

    char pop()
    {
        char c = head->info;
        CharLinkedList p = head;
        head = head->next;
        delete p;
        return c;
    }

    void print ( ostream & out )
    {
        for ( CharLinkedList p = head; p != 0; p = p->next )
        {
            out << p->info << ' ';
        }
    }

    void push ( char c )
    {
        head = new CharLinkedListPair ( c, head );
    }

};
#endif