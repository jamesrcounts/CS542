/***************************************************
hw2.cpp

Jim Counts
CS 542 - OO
Homework 2
**************************************************/

#include <iostream>

#include "LinkedStackMember.h"
#include "LinkedStackMemento.h"
#include "LinkedStack.h"
#include "LinkedStackIterator.h"

using namespace std;

/*
Prints the stack with a label
*/
void print_stack(string label, LinkedStack & s)
{
    cout << label << endl;
    cout << s << endl;
}

/*
The main entry point for the program.
*/
int main ( int argc, const char * argv[] )
{
    cout << "Jim Counts" << endl;
    cout << "CS 542 Homework 2" << endl << endl;

    LinkedStack s;

    cout << "Test Memento" << endl;
    print_stack("Empty Stack:", s);

    LinkedStackMemento * empty = s.createMemento();
    s.push('t');
    print_stack("One: ", s);

    LinkedStackMemento * one = s.createMemento();
    s.push('a');
    s.push('c');
    for(char c = 'A'; c <= 'Z'; ++c)
    {
        s.push(c);
    }
    print_stack("Full: ", s);

    LinkedStackMemento * full = s.createMemento();

    cout << "Restore Empty" << endl;
    s.restore(empty);
    print_stack("Restored Empty:", s);

    cout << "Restore Full" << endl;
    s.restore(full);
    print_stack("Restored Full:", s);

    cout << "Restore One" << endl;
    s.restore(one);
    print_stack("Restored One:", s);

    cout << "Done" << endl;

    delete empty;
    delete one;
    delete full;
}
