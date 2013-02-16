#ifndef LINKEDSTACKMEMENTO_H
#define LINKEDSTACKMEMENTO_H 1

class LinkedStack;

// (30 points) Write the LinkedStackMemento for LinkedStack.
class LinkedStackMemento
{
    friend class LinkedStack;
    char * state;
    int size;
    LinkedStackMemento(LinkedStack * stack);
    void restore(LinkedStack * stack);
public:
    ~LinkedStackMemento()
    {
        delete state;
    }
};

#endif