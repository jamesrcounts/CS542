#include "LinkedStackMemento.h"

LinkedStackMemento::LinkedStackMemento(LinkedStack * stack)
{
    size = stack->size();
    state = new char[size];
    int i = 0;
    for(LinkedStackNode p = stack->head; p != 0; p = p->next)
    {
        state[i++] = p->value;
    }
}

void LinkedStackMemento::restore(LinkedStack * stack) {}

LinkedStackMemento::~LinkedStackMemento()
{
    delete state;
}
