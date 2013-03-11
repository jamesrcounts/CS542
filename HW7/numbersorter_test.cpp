/* test.cpp */

#include <igloo/igloo.h>
#include "NumberSorter.h"

using namespace std;
using namespace igloo;

Context( DescribeANumberSorter )
{
    stringstream spy;
    Spec( ItReadsIntegersFromAStream )
    {
        NumberSorter ns;
        stringstream numbers( "10 21 32 43" );
        ns.read( numbers );
        ns.print( spy );
        Assert::That( spy.str(), Equals( "(unsorted) 10 21 32 43 " ) );
    }

    Spec( ItSortsTheIntegers )
    {
        NumberSorter ns;
        stringstream numbers( "10 32 21 43" );

        ns.read( numbers );
        ns.sort();
        ns.print( spy );
        Assert::That( spy.str(), Equals( "(sorted) 10 21 32 43 " ) );
    }

    Spec( ItFormatsTheOddIntegers )
    {
        NumberSorter ns;
        stringstream numbers( "32 10 43 21" );

        ns.read( numbers );
        ns.sort();
        ns.print_odd( spy );
        Assert::That( spy.str(), Equals( "21 43 " ) );
    }

    Spec( ItFormatsTheEvenIntegers )
    {
        NumberSorter ns;
        stringstream numbers( "32 10 43 21" );
        ns.read( numbers );
        ns.sort();
        ns.print_even( spy );
        Assert::That( spy.str(), Equals( "10\n32\n" ) );
    }
};

int main( )
{
    return TestRunner::RunAllTests();
}