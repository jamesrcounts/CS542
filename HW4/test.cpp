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
    Spec( ReadString )
    {
        stringstream in( "Hello World" );
        String text( "Goodbye" );
        text.read( in );
        Assert::That( text.c_str(), Equals( "Hello World" ) );
    }

    Spec( PrintString )
    {
        String text( "Hello World" );
        stringstream out;
        text.print( out );
        Assert::That( out.str(), Equals( "Hello World" ) );
    }

    Spec( IndexOfMultiplePartialMatches )
    {
        String text( "BESS KNEW ABOUT BAOBABS" );
        String pattern( "BAOBAB" );
        int x = text.indexOf( pattern );
        Assert::That( x, Equals( 16 ) );
    }

    Spec( IndexOfPartialPatternMatch )
    {
        String source( "0ABCDEFG" );
        String pattern( "CEF" );
        int x = source.indexOf( pattern );
        Assert::That( x, Equals( -1 ) );
    }

    Spec( IndexOfMissingPattern )
    {
        String source( "ABCDEFG" );
        String pattern( "ZZ" );
        int x = source.indexOf( pattern );
        Assert::That( x, Equals( -1 ) );
    }

    Spec( IndexOfPattern )
    {
        String source( "ABBACCCADDDD" );
        String pattern( "BAC" );
        int x = source.indexOf( pattern );
        Assert::That( x, Equals( 2 ) );
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

    Spec( GetReservedString )
    {
        String expected( "olleH" );
        String source( "Hello" );
        String received = source.reverse();
        Assert::That( received.c_str(), Equals( expected.c_str() ) );
        Assert::That( source.c_str(), Equals( "Hello" ) );
    }

    Spec( GetSize )
    {
        String target( "Test String" );
        Assert::That( target.size(), Equals( 11 ) );
    }

};

Context( UsingStringOperators )
{
    Spec( InsertionOperator )
    {
        String text( "Goodbye" );
        stringstream in( "Hello World" );
        in >> text;
        Assert::That( text.c_str(), Equals( "Hello World" ) );
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
        Assert::That( hello.c_str(), Equals( "Hello World" ) );
    }

    Spec( ConcatenateWithPlus )
    {
        String hello( "Hello" );
        String space( " " );
        String world( "World" );
        String hello_world = hello + space + world;
        Assert::That( hello_world.c_str(), Equals( "Hello World" ) );
    }

    Spec( LeftLessThanOrEqualToRight )
    {
        String i( "Hellp" );
        String j( "Hello" );
        String k( "Hello" );
        Assert::That( j <= i, Equals( 1 ) );
        Assert::That( j <= k, Equals( 1 ) );
        Assert::That( i <= j, Equals( 0 ) );
    }

    Spec( LeftGreaterThanOrEqualToRight )
    {
        String i( "Hellp" );
        String j( "Hello" );
        String k( "Hello" );
        Assert::That( i >= j, Equals( 1 ) );
        Assert::That( j >= k, Equals( 1 ) );
        Assert::That( j >= i, Equals( 0 ) );
    }

    Spec( LessThan )
    {
        String i( "Hello" );
        String j( "Hello" );
        String k( "Hellp" );
        Assert::That( i < j, Equals( 0 ) );
        Assert::That( i < k, Equals( 1 ) );
    }

    Spec( GreaterThan )
    {
        String i( "Hello" );
        String j( "Hello" );
        String k( "Hellp" );
        Assert::That( i > j, Equals( 0 ) );
        Assert::That( k > i, Equals( 1 ) );
    }

    Spec( Equality )
    {
        String i( "Hello" );
        String j( "Hello" );
        String k( "Bye" );
        Assert::That( i == j, Equals( 1 ) );
        Assert::That( i == k, Equals( 0 ) );
        Assert::That( i != k, Equals( 1 ) );
        Assert::That( i != j, Equals( 0 ) );
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

        Assert::That( target.c_str(), Equals( source.c_str() ) );
        Assert::That( &target, !Equals( &source ) );
    }

};

Context( StringConstructors )
{
    Spec( CopyString )
    {
        String source( "Hello World" );
        String received( source );
        Assert::That( received.c_str(), Equals( source.c_str() ) );
    }

    Spec( CopyCStr )
    {
        const char *source = "Hello World";
        String received( source );
        Assert::That( received.c_str(), Equals( source ) );
    }
};
