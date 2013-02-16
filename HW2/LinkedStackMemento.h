#ifndef LINKEDSTACKMEMENTO_H
#define LINKEDSTACKMEMENTO_H

class LinkedStack;

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
