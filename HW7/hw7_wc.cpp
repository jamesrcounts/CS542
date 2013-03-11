/* hw7.cpp */

#include <iostream>
#include <fstream>
#include "WordCounter.h"

using namespace std;

int main( int argc, char const *argv[] )
{
    cout << "Jim Counts" << endl;
    cout << "CS 542 - OO" << endl;
    cout << "Homework 7" << endl << endl;

    WordCounter wc;

    ifstream excludefile( "exclude.txt", ifstream::in );
    wc.mustExclude( excludefile );
    excludefile.close();

    ifstream infile( "words.txt", ifstream::in );
    wc.count( infile );
    infile.close();

    cout << wc;
    return 0;
}



