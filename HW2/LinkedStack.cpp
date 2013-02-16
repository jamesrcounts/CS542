#include "LinkedStack.h"

LinkedStackMemento * LinkedStack::createMemento()
{
    return new LinkedStackMemento( this );
}
