/***************************************************
test.cpp

Jim Counts
CS 542 - OO
Homework 3
**************************************************/

#include "String.h"
#include <igloo/igloo.h>
#include <sstream>

using namespace std;
using namespace igloo;

int main()
{
    return TestRunner::RunAllTests();
}

Context( UsingStringFunctions )
{
    Spec( Length )
    {
        String s( "Hello" );
        Assert::That( s.length(), Equals( 5 ) );
    }

    Spec( ReadString )
    {
        stringstream in( "Hello World" );
        String text( "Goodbye" );
        String expected( "Hello World" );
        text.read( in );
        Assert::That( text, Equals( expected ) );
    }

    Spec( PrintString )
    {
        String text( "Hello World" );
        stringstream out;
        text.print( out );
        Assert::That( out.str(), Equals( "Hello World" ) );
    }

    Spec( IndexOfMissingCharacter )
    {
        String source( "ABCDEFG" );
        int x = source.indexOf( 'Z' );
        Assert::That( x, Equals( -1 ) );
    }

    Spec( IndexOfCharacter )
    {
        String source( "ABCDEFG" );
        int x = source.indexOf( 'D' );
        Assert::That( x, Equals( 3 ) );
    }
};

Context( UsingStringOperators )
{
    Spec( InsertionOperator )
    {
        String text( "Goodbye" );
        stringstream in( "Hello World" );
        in >> text;
        Assert::That( text, Equals( String( "Hello World" ) ) );
    }

    Spec( ExtractionOperator )
    {
        String text( "Hello World" );
        stringstream out;
        out << text;
        Assert::That( out.str(), Equals( "Hello World" ) );
    }

    Spec( ConcatenateWithPlusEqual )
    {
        String hello( "Hello" );
        String space( " " );
        String world( "World" );
        hello += space += world;
        Assert::That( hello, Equals( String( "Hello World" ) ) );
    }

    Spec( ConcatenateWithPlus )
    {
        String hello( "Hello" );
        String space( " " );
        String world( "World" );
        String hello_world = hello + space + world;
        Assert::That( hello_world, Equals( String( "Hello World" ) ) );
    }

    Spec( Equality )
    {
        String i( "Hello" );
        String j( "Hello" );
        String k( "Bye" );
        Assert::That( i == j, Equals( 1 ) );
        Assert::That( i == k, Equals( 0 ) );
    }

    Spec( AccessByValidIndex )
    {
        String s( "Hello World" );
        char c = s[2];
        Assert::That( c, Equals( 'l' ) );
    }

    Spec( CopyByAssignment )
    {
        String source( "Hello World" );
        String target( "Goodbye" );

        target = source;

        Assert::That( target, Equals( source ) );
        Assert::That( &target, !Equals( &source ) );
    }

};

Context( StringConstructors )
{
    Spec( CopyString )
    {
        String source( "Hello World" );
        String received( source );
        Assert::That( received, Equals( source ) );
    }

    Spec( CopyCStr )
    {
        const char *source = "Hello World";
        String received( source );
        stringstream out;
        out << received;
        Assert::That( out.str() , Equals( source ) );
    }
};
