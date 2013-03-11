#ifndef COPYIF_H
#define COPYIF_H 

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


#endif