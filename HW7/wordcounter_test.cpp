/* test.cpp */

#include <igloo/igloo.h>
#include "WordCounter.h"

using namespace std;
using namespace igloo;

Context( DescribeAWordCounter )
{
    Spec( ItCountsWordsInAStream )
    {
        WordCounter it;
        stringstream example( "word word map map map" );
        it.count( example );
        Assert::That( it.countOf( "map" ), Equals( 3 ) );
    }

    Spec( ItMakesWordsLowerCase )
    {
        WordCounter it;
        stringstream example( "word word Map map MAP" );
        it.count( example );
        Assert::That( it.countOf( "map" ), Equals( 3 ) );
    }

    Spec( ItRemovesPunctuation )
    {
        WordCounter it;
        stringstream example( "word word map map, map" );
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