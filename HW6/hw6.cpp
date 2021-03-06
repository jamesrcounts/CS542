/* hw6.cpp */

#include <iostream>
#include "Matrix.h"

using namespace std;

template < class T >
void fillMatrix( Matrix <T> & m )
{
    int i, j;

    for ( i = 0; i < m.numRows(); i++ )
    {
        m[i][0] = T();
    }

    for ( j = 0; j < m.numCols(); j++ )
    {
        m[0][j] = T();
    }

    for ( i = 1; i < m.numRows(); i++ )
    {
        for ( j = 1; j < m.numCols(); j++ )
        {
            m[i][j] = T( i * j );
        }
    }
}

int main( int argc, char const *argv[] )
{
    cout << "Jim Counts" << endl;
    cout << "CS 542 - OO" << endl;
    cout << "Homework 6" << endl << endl;

    try
    {
        Matrix<int> m( 10, 5 );
        fillMatrix( m );
        cout << m << endl;
        Matrix<double> M( 8, 10 );
        fillMatrix( M );
        cout << M << endl;

        M[M.numRows()][0] = 99;
    }
    catch ( exception &e )
    {
        cout << e.what() << " in main." << endl;
    }

    return 0;
}



