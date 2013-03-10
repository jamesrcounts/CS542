/* test.cpp */

#include <igloo/igloo.h>
#include <iomanip>
#include "Array.h"

using namespace std;
using namespace igloo;

void InitializeArray( Array<int> &a )
{
    for ( int i = 0; i < a.length(); ++i )
    {
        a[i] = 0;
    }
}

void IllegalAssignment( Array<int> &a )
{
    a[a.length()] = 42;
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

    Spec( ItThrowsExceptionsWhenIndexIsOutOfBounds )
    {
        Array<int> it( 10 );
        InitializeArray( it );
        AssertThrows( IndexOutOfBoundsException, IllegalAssignment( it ) );
        Assert::That( LastException<IndexOutOfBoundsException>().what(),
                      Equals( "Index is out of bounds." ) );
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