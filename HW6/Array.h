#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>
#include <iomanip>
#include <sstream>

using namespace std;

class IndexOutOfBoundsException: public exception
{
public:
    virtual const char *what() const throw()
    {
        return "Index is out of bounds";
    }
} oobex;

template <class Element>
class Array
{
private:
    int sz;
    Element *buf;
public:
    Array( int size ) : sz( size ), buf( new Element[sz] ) {}

    Array( Array &l ) : sz( l.sz ), buf( new Element[l.sz] )
    {
        for ( int i = 0; i < l.sz; i++ )
        {
            buf[i] = l.buf[i];
        }
    }

    ~Array()
    {
        delete[] buf;
    }

    int length()
    {
        return sz;
    }

    void print( ostream &out )
    {
        for ( int i = 0; i < sz; i++ )
        {
            out << setw( 5 ) << buf[i];
        }
    }

    Element &operator []( int i )
    {
        if ( i < 0 || sz <= i )
        {
            throw oobex;
        }

        return buf[i];
    }

    friend ostream &operator << ( ostream &out, Array &a )
    {
        a.print( out );
        return out;
    }

    friend ostream &operator << ( ostream &out, Array *ap )
    {
        ap->print( out );
        return out;
    }
};
#endif