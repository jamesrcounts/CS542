/* test.cpp */

#include <igloo/igloo.h>

using namespace std;
using namespace igloo;

class WordCounter
{
    map<string, int> wc;
    vector<string> ex;
public:
    WordCounter() {}
    ~WordCounter() {}

    void count( istream &in )
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

    int countOf( string word )
    {
        return wc[word];
    }

    void mustExclude( istream &in )
    {
        string word;

        while ( in >> word )
        {
            ex.push_back( word );
        }
    }

    void print( ostream &out )
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

    friend ostream &operator<<( ostream &out, WordCounter &it )
    {
        it.print( out );
        return out;
    }
};

Context( DescribeAWordCounter )
{
    Spec( ItCountsWordsInAStream )
    {
        WordCounter it;
        stringstream example( "word word map map map" );
        it.count( example );
        Assert::That( it.countOf( "map" ), Equals( 3 ) );
    }

    Spec( CertainWordsCanBeExcluded )
    {
        WordCounter it;
        stringstream exclude( "as a an or the and but" );
        it.mustExclude( exclude );
        stringstream words( "as a word an word or the map and map but map" );
        it.count( words );
        Assert::That( it.countOf( "but" ), Equals( 0 ) );
    }

    Spec( ItCanBePrinted )
    {
        WordCounter it;
        stringstream exclude( "as a an or the and but" );
        it.mustExclude( exclude );
        stringstream words( "as a word and word or the map and map but map" );
        it.count( words );
        it.countOf( "as" );
        stringstream spy;
        it.print( spy );
        Assert::That( spy.str(), Equals( "map => 3\nword => 2\n" ) );
    }

    Spec( ItCanBeInsertedIntoAStream )
    {
        WordCounter it;
        stringstream words( "word word map map map" );
        it.count( words );
        stringstream spy;
        spy << it;
        Assert::That( spy.str(), Equals( "map => 3\nword => 2\n" ) );
    }
};

int main( )
{
    return TestRunner::RunAllTests();
}