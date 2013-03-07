/* hw5.cpp */

#include <iostream>
#include <vector>

#include "Alien.h"
#include "Animal.h"
#include "Horse.h"
#include "Snake.h"

using namespace std;

void MoveAnimals( vector<Animal *> animals )
{
    for ( vector<Animal *>::iterator it = animals.begin();
            it != animals.end();
            ++it )
    {
        Animal *a = *it;
        a->Move();
    }
}

int main( int argc, char const *argv[] )
{
    cout << "Jim Counts" << endl;
    cout << "CS 542 - OO" << endl;
    cout << "Homework 5" << endl << endl;

    vector<Animal *> group;
    group.push_back( new Snake() );
    group.push_back( new Horse() );
    group.push_back( new Alien() );

    MoveAnimals( group );

    for ( vector<Animal *>::iterator it = group.begin();
            it != group.end();
            ++it )
    {
        delete *it;
    }

    return 0;
}