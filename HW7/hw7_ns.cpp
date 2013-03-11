/* hw7.cpp */

#include <iostream>
#include <fstream>
#include "NumberSorter.h"

using namespace std;

/*
1. (40 points) Write a program that reads a sequence of integers from a file (or
 from cin if you prefer). It should sort them, then write the odd ones to one
 file (separated by a space), then write the even ones to another file, one per
 line.
2. Note you can use ifstream and ofstream for creating I/O streams bound to name
 files and use stream iterators for reading and writing the named files.
 */

int main( int argc, char const *argv[] )
{
    cout << "Jim Counts" << endl;
    cout << "CS 542 - OO" << endl;
    cout << "Homework 7" << endl << endl;

    NumberSorter ns;

    ifstream infile( "integers.txt", ifstream::in );
    ns.read( infile );
    infile.close();

    ns.sort();

    ofstream odd( "odd.txt", ofstream::out );
    ns.print_odd( odd );
    odd.close();

    ofstream even( "even.txt", ofstream::out );
    ns.print_even( even );
    even.close();

    cout << "done." << endl;
    return 0;
}



