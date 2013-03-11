#include "NumberSorter.h"
#include <algorithm>
#include <iterator>

using namespace std;

bool is_even( int i )
{
    return( i % 2 == 0 );
}

bool is_odd( int i )
{
    return ( i % 2 == 1 );
}

/*
| Backported from C++ 11 via:
| http://www.cplusplus.com/reference/algorithm/copy_if/
*/
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

NumberSorter::NumberSorter() : sorted( false ) {}

void NumberSorter::read( istream &in )
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

void NumberSorter::sort()
{
    std::sort( ns.begin(), ns.end() );
    sorted = true;
}

void NumberSorter::print( ostream &out )
{
    out << ( sorted ? "(sorted) " : "(unsorted) " );

    ostream_iterator<int> out_it( out, " " );
    copy( ns.begin(), ns.end(), out_it );
}

void NumberSorter::print_even( ostream &out )
{
    ostream_iterator<int> it( out, "\n" );
    copy_if( ns.begin(), ns.end(), it, &is_even );
}

void NumberSorter::print_odd( ostream &out )
{
    ostream_iterator<int> it( out, " " );
    copy_if( ns.begin(), ns.end(), it, &is_odd );
}
