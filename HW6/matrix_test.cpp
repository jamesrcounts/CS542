/* test.cpp */

#include <igloo/igloo.h>
#include <iomanip>
#include "Array.h"
#include "Matrix.h"

using namespace std;
using namespace igloo;

void InitializeMatrix( Matrix<int> &it )
{
    for ( int i = 0; i < it.numRows(); ++i )
    {
        for ( int j = 0; j < it.numCols(); ++j )
        {
            it[i][j] = 0;
        }
    }
}

Context( DescribeAMatrix )
{
    Spec( ItHasFixedRowsAndColumns )
    {
        Matrix<int> it( 5, 10 );
        Assert::That( it.numRows(), Equals( 5 ) );
        Assert::That( it.numCols(), Equals( 10 ) );
    }

    Spec( ItsRowsAreComposedOfMutableCells )
    {
        Matrix<int> it( 2, 2 );
        it[1][1] = 99;
        Assert::That( it[1][1], Equals( 99 ) );
    }

    Spec( ItIsPrintable )
    {
        Matrix<int> it( 2, 2 );
        InitializeMatrix( it );

        string expected( "    0    0\n    0    0\n" );
        stringstream spy;
        it.print( spy );
        Assert::That( spy.str(), Equals( expected ) );
    }

    Spec( ItIsExtractable )
    {
        Matrix<int> it( 2, 2 );
        InitializeMatrix( it );

        string expected( "    0    0\n    0    0\n" );
        stringstream spy;
        spy << it;
        Assert::That( spy.str(), Equals( expected ) );

    }

    Spec( ItIsATemplateClass )
    {
        Matrix<float> it( 2, 2 );

        for ( int i = 0; i < it.numRows(); ++i )
        {
            for ( int j = 0; j < it.numCols(); ++j )
            {
                it[i][j] = i * j * 0.5f;
            }
        }

        string expected( "    0    0\n    0  0.5\n" );
        stringstream spy;
        spy << it;
        Assert::That( spy.str(), Equals( expected ) );
    }
};

int main( )
{
    return TestRunner::RunAllTests();
}