#include "WordCounter.h"
#include "copyif.h"
#include <iterator>
#include <sstream>

using namespace std;

bool not_punctuation( char c )
{
    string punctuation = "'[](){}:,-_.!?\";\\/@#$%^&*+|~`<>";
    return ( punctuation.find_first_of( c ) == string::npos );
}

string WordCounter::erase_punctuation( string s )
{
    stringstream result;
    ostream_iterator<char> it( result );
    copy_if( s.begin(), s.end(), it, &not_punctuation );
    return result.str();
}

void WordCounter::count( istream &in )
{
    string word;

    while ( in >> word )
    {
        word = erase_punctuation( word );
        transform( word.begin(), word.end(), word.begin(), ::tolower );
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

