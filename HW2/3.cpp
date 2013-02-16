#include <iostream>
using namespace std;

#include "LinkedStackMember.h"
#include "LinkedStackMemento.h"
#include "LinkedStack.h"
#include "LinkedStackIterator.h"

// (30 points) Write factory Methods for creating iterators
LinkedStackIterator * LinkedStack::createIterator()
{
    return new LinkedStackIterator( this );
}
LinkedStackMemento::LinkedStackMemento(LinkedStack * stack)
{
    size = stack->size();
    state = new char[size];
    int i;
    LinkedStackNode p;
    for ( p = stack->head, i = 0; p != 0; p = p->next )
        state[i++] = p->value;
}
void LinkedStackMemento::restore(LinkedStack* stack)
{
    while(!stack->isEmpty())
    {
        stack->pop();
    }

    for ( int i = size; i > 0; )
        stack->push(state[--i]);
}
// (40 points) b) .. write operator << for Stack using the LinkedStackIterator
ostream & operator << (ostream & out, LinkedStack & stk)
{
    LinkedStackIterator & i = *stk.createIterator();
    for(; !i.end(); i.moveNext())
    {
        out << " " << i.current();
    }

    delete &i;
    return out;
}
int main()
{
    LinkedStack stack;
    cout << "Memento test" << endl;
    stack.print(cout);
    LinkedStackMemento * emptyMemento = stack.createMemento();
    cout << "Empty: " << stack << endl;
    stack.push('t');
    LinkedStackMemento * oneMemento = stack.createMemento();
    cout << "One: " << stack << endl;
    stack.push('a');
    stack.push('c');
    for (  char c = 'A'; c <= 'Z'; ++c )
        stack.push(c);
    LinkedStackMemento * fullMemento = stack.createMemento();
    cout << "Full: " << stack << endl;
    cout << endl;
    for ( char c = 'A'; c <= 'Z'; ++c )
        stack.push(c);
    stack.restore(emptyMemento);
    cout << "Empty: " << stack << endl;
    stack.restore(fullMemento);
    cout << "Full: " << stack << endl;
    stack.restore(oneMemento);
    cout << "One: " << stack << endl;
    cout << "Iterator test" << endl;
    stack.restore(fullMemento);
    cout << stack;
    cout << endl << "Done" << endl;
    delete emptyMemento;
    delete oneMemento;
    delete fullMemento;
    return 0;
}