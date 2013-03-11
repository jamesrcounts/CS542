#include "WordCounter.h"

using namespace std;

void WordCounter::count( istream &in )
{
    string word;

    while ( in >> word )
    {
        vector<string>::iterator it;
        it = find( ex.begin(), ex.end(), word );

        if ( it == ex.end() )
        {
            wc[word]++;
        }
    }
}

int WordCounter::countOf( string word )
{
    return wc[word];
}

void WordCounter::mustExclude( istream &in )
{
    string word;

    while ( in >> word )
    {
        ex.push_back( word );
    }
}

void WordCounter::print( ostream &out )
{
    for ( map<string, int>::iterator it = wc.begin();
            it != wc.end();
            ++it )
    {
        if ( 0 < it->second )
        {
            out << it->first << " => " << it->second << endl;
        }
    }
}

