/* test.cpp */

#include <igloo/igloo.h>
#include <iterator>

using namespace std;
using namespace igloo;

bool is_even( int i )
{
    return( i % 2 == 0 );
}

bool is_odd( int i )
{
    return ( i % 2 == 1 );
}

template <class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator copy_if( InputIterator first, InputIterator last,
                        OutputIterator result, UnaryPredicate pred )
{
    while ( first != last )
    {
        if ( pred( *first ) )
        {
            *result = *first;
            ++result;
        }

        ++first;
    }

    return result;
}

class NumberSorter
{
private:
    bool sorted;
    std::vector<int> ns;
public:
    NumberSorter() : sorted( false ) {}

    void read( istream &in )
    {
        istream_iterator<int> eos;

        for ( istream_iterator<int> iit( in );
                iit != eos;
                ++iit )
        {
            ns.push_back( *iit );
        }

        sorted = false;
    }

    void sort()
    {
        std::sort( ns.begin(), ns.end() );
        sorted = true;
    }

    void print( ostream &out )
    {
        out << ( sorted ? "(sorted) " : "(unsorted) " );

        ostream_iterator<int> out_it( out, " " );
        copy( ns.begin(), ns.end(), out_it );
    }

    void print_even( ostream &out )
    {
        ostream_iterator<int> it( out, "\n" );
        copy_if( ns.begin(), ns.end(), it, &is_even );
    }

    void print_odd( ostream &out )
    {
        ostream_iterator<int> it( out, " " );
        copy_if( ns.begin(), ns.end(), it, &is_odd );
    }
};

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