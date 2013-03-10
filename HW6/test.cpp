/* test.cpp */

#include <igloo/igloo.h>
#include <iomanip>
#include "Array.h"

using namespace std;
using namespace igloo;

/*
template
< class Element >
class Matrix
{
private:
   int rows, cols;
 // define m as an Array of Array pointers using the template
 // you defined above
public:
   Matrix( int newRows, int newCols )
   : rows( newRows ), cols( newCols ), m( rows )
   {
     for (int i = 0; i < rows; i++ )
       m[i] = new Array < Element >( cols );
}
int numRows()
{
 return rows;
}
int numCols()
{
 return cols;
}
Array < Element > & operator [] ( int row )
{
 return * m[row];
}
void print( ostream & out )
{
   // You can write this one too, but use the Array::operator<<
}
friend ostream & operator << ( ostream & out, Matrix & m )
{
 m.print( out );
 return out;
}
};
*/


void InitializeArray( Array<int> &a )
{
    for ( int i = 0; i < a.length(); ++i )
    {
        a[i] = 0;
    }
}

Context( DescribeAnArray )
{
    Spec( ItIsATemplateClass )
    {
        Array<float> it( 3 );

        for ( int i = 0; i < it.length(); ++i )
        {
            it[i] = i * 0.5f;
        }

        stringstream spy;
        it.print( spy );
        Assert::That( spy.str(), Equals( "    0  0.5    1" ) );
    }

    Spec( ItHasADefinedLength )
    {
        Array<int> it( 10 );
        Assert::That( it.length(), Equals( 10 ) );
    }

    Spec( ItHasMutableCells )
    {
        Array<int> it( 10 );
        it[5] = 99;
        Assert::That( it[5], Equals( 99 ) );
    }

    Spec( ItIsPrintable )
    {
        string expected( "    0    0    0" );
        stringstream spy;
        Array<int> it( 3 );
        InitializeArray( it );

        it.print( spy );
        Assert::That( spy.str(), Equals( expected ) );
    }

    Spec( ItCanBeExtractedByReference )
    {
        string expected( "    0    0    0" );
        stringstream spy;
        Array<int> it( 3 );
        InitializeArray( it );

        spy << it;
        Assert::That( spy.str(), Equals( expected ) );
    }

    Spec( ItCanBeExtractedByPointer )
    {
        string expected( "    0    0    0" );
        stringstream spy;
        Array<int> *it = new Array<int>( 3 );
        InitializeArray( *it );
        spy << it;
        Assert::That( spy.str(), Equals( expected ) );
        delete it;
    }

    Spec( ItCanBeCopiedIntoAnotherArray )
    {
        string expected( "    1    2    3" );
        Array<int> other( 3 );

        for ( int i = 0; i < other.length(); ++i )
        {
            other[i] = i + 1;
        }

        Array<int> it( other );

        stringstream spy;
        it.print( spy );
        Assert::That( spy.str(), Equals( expected ) );
    }
};

int main( )
{
    return TestRunner::RunAllTests();
}