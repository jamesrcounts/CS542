#include "LinkedStackMemento.h"
#include "LinkedStack.h"

LinkedStackMemento::LinkedStackMemento(LinkedStack * stack)
{
    size = stack->size();
    state = new char[size];
    int i = 0;
    LinkedStackNode p;
    for ( p = stack->head; p != 0; p = p->next )
    {
        state[i++] = p->value;
    }
}

void LinkedStackMemento::restore(LinkedStack* stack)
{
    while(!stack->isEmpty())
    {
        stack->pop();
    }

    for ( int i = size; i > 0; )
    {
        stack->push(state[--i]);
    }
}
