#ifndef LINKEDSTACKITERATOR_H
#define LINKEDSTACKITERATOR_H

#include "LinkedStack.h"

class LinkedStackIterator
{
    LinkedStack * collection;
    LinkedStackMember * index;
public:
    LinkedStackIterator(LinkedStack * s)
    {
        collection = s;
        reset();
    }

    char current()
    {
        return index->value;
    }

    bool end()
    {
        return index == 0;
    }

    void moveNext()
    {
        index = index->next;
    }

    void reset()
    {
        index = collection->head;
    }
};

ostream & operator << (ostream & out, LinkedStack & s);

#endif