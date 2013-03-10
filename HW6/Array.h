#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>
#include <iomanip>
#include <sstream>

using namespace std;

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
        assert( 0 <= i && i < sz );
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