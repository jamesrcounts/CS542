/* hw4.cpp */

#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    cout << "Jim Counts" << endl;
    cout << "CS 542 - OO" << endl;
    cout << "Homework 4" << endl << endl;

    cout << "Demonstrate String functionality:" << endl;

    cout << endl << "Construction" << endl;
    cout << "Construct from C-String... ";

    const char *source = "Hello";
    String hello( source );

    cout << hello << endl;

    cout << "Construct from another String... ";

    String w( "World" );
    String world( w );

    cout << world << endl;

    cout << endl << "Operators" << endl;

    cout << "Insertion Operator... " << endl;
    cout << "Enter a string: " ;
    String inserted;
    cin >> inserted;

    cout << "Inserted your input from STDIN." << endl;
    cout << "Extraction Operator... " << endl;
    cout << "Your input from STDIN... ";
    cout << inserted << endl;

    String space( " " );
    hello += space += world;
    cout << "Addition/Assignment (+=) updates through concatenation... " << endl;
    cout << "hello += space += world;" << endl;
    cout << "hello is now: " << hello << endl;
    cout << "space is now: " << space << endl;
    cout << "world is unchanged: " << world << endl;

    String jim( "Jim" );
    String blank( " " );
    String counts( "Counts" );
    String jim_counts = jim + blank + counts;
    cout << "Addition (+) performs concatenation... " << endl;
    cout << "jim_counts = jim + blank + counts" << endl;
    cout << "jim_counts is: " << jim_counts << endl;
    cout << "jim is unchanged: " << jim << endl;
    cout << "blank is unchanged: " << blank << endl;
    cout << "counts is unchanged: " << counts << endl;

    cout << "Equality... " << endl;
    cout << jim << " == " << counts << "... ";
    cout << ( jim == counts ? "true" : "false" ) << endl;
    cout << jim << " == " << jim << "... ";
    cout << ( jim == jim ? "true" : "false" ) << endl;

    cout << "Indexing... " << endl;
    cout << "counts[3]... " << counts[3] << endl;

    hello = world;
    cout << "Assignment... " << endl;
    cout << "hello = world... ";
    cout << hello << endl;

    cout << endl << "Functions" << endl;

    String text( "BESS KNEW ABOUT BAOBABS" );
    cout << "String.indexOf (char)" << endl;
    cout << "TEXT: " << text << endl;
    cout << "CHAR: 'U'" << endl;
    cout << "CHAR found at... " << text.indexOf( 'U' ) << endl;

    cout << "Done with demonstration." << endl;

    return 0;
}
