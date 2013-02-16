#include "LinkedStackIterator.h"
#include "LinkedStackMemento.h"
#include "LinkedStack.h"

LinkedStackMemento * LinkedStack::createMemento()
{
    return new LinkedStackMemento( this );
}

LinkedStackIterator * LinkedStack::createIterator()
{
    return new LinkedStackIterator( this );
}

ostream & operator << (ostream & out, LinkedStack & s)
{
    LinkedStackIterator & i = *s.createIterator();
    for(; !i.end(); i.moveNext())
    {
        out << " " << i.current();
    }

    delete &i;
    return out;
}
