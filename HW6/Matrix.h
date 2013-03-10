#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"

template <class Element>
class Matrix
{
private:
    int rows;
    int cols;
    Array<Array<Element> * > m;
public:
    Matrix( int r, int c ) : rows( r ), cols( c ), m( r )
    {
        for ( int i = 0; i < rows; ++i )
        {
            m[i] = new Array < Element >( cols );
        }

    }

    ~Matrix()
    {
        for ( int i = 0; i < rows; ++i )
        {
            delete m[i];
        }
    }

    int numRows()
    {
        return rows;
    }

    int numCols()
    {
        return cols;
    }

    void print( ostream &out )
    {
        for ( int i = 0; i < rows; ++i )
        {
            out << m[i] << endl;
        }
    }

    Array < Element > & operator []( int row )
    {
        return * m[row];
    }

    friend ostream &operator << ( ostream &out, Matrix &m )
    {
        m.print( out );
        return out;
    }
};

#endif