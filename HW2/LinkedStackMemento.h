#ifndef LINKEDSTACKMEMENTO_H
#define LINKEDSTACKMEMENTO_H
#include "LinkedStack.h"

class LinkedStackMemento
{
    friend class LinkedStack;
    char * state;
    int size;
    LinkedStackMemento(LinkedStack * stack)
    {
        size = stack->size();
        state = new char[size];
        int i = 0;
        for(CharLinkedList p = stack->head; p != 0; p = p->next)
        {
            state[i++] = p->info;
        }
    }

    void restore(LinkedStack * stack)
    {
        while(!stack->isEmpty())
        {
            stack->pop();
        }

        for(int i = dataSize; i > 0;)
        {
            stack->push(state[--i]);
        }

    }

public:
    ~LinkedStackMemento()
    {
        delete state;
    }
};
#endif