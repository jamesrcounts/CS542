#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal
{
private:
    ostream *logger;
protected:
    int stride;
    void WriteToLog( string message );
    Animal():  logger( &cout ), stride( 1 ) {}
public:
    virtual ~Animal() {};
    virtual void Move() = 0;
    void UseSpy( ostream &spy );
};

#endif