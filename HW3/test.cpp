/***************************************************
test.cpp

Jim Counts
CS 542 - OO
Homework 3
**************************************************/

#include <igloo/igloo.h>
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;
using namespace igloo;

class String
{
public:
    String( const char *s = "" )
    {
        buf = NULL;
        len = string_length( s );
        buf = string_copy( buf, s, len );
    }

    String( const String &s )
    {
        buf = NULL;
        buf = string_copy( buf, s.buf, s.len );
        len = s.len;
    }

    int indexOf( char c )
    {
        char t[2] = {c, 0};
        return string_index( buf, size(), t, 1 );
    }

    int indexOf( String pattern )
    {
        return string_index( buf, size(), pattern.buf, pattern.size() );
    }

    void print( ostream &out )
    {
        out << buf;
    }

    void read( istream &in )
    {
        int buf_size = 1024;
        char *buffer = new char[buf_size];
        int result_size = 0;
        char *result = new char[result_size];

        while ( in )
        {
            in.read( buffer, buf_size );
            int i = in.gcount();

            if ( i )
            {
                char *t = result;
                result = new char[result_size + i];
                memcpy( result, t, result_size );
                memcpy( result + result_size, buffer, i );
                result_size += i;
                delete[] t;
            }
        }

        delete[] buffer;
        buf = string_copy( buf, result, result_size );
        len = result_size;
    }

    String reverse()
    {
        int i = 0;
        int j = size() - 1;

        char *reversed = new char[len];

        while ( i < len )
        {
            reversed[i++] = buf[j--];
        }

        String *r = new String( reversed );
        return *r;
    }

    int size()
    {
        return len - 1;
    }

    const char *c_str()
    {
        return buf;
    }

    ~String()
    {
        delete[] buf;
    }

    String &operator = ( const String &s )
    {
        buf = string_copy( buf, s.buf, s.len );
        len = s.len;

        return *this;
    }

    char &operator []( int index )
    {
        assert( inBounds( index ) );
        return buf[index];
    }

    bool operator == ( const String &s ) const
    {
        if ( len == s.len )
        {
            return memcmp( buf, s.buf, len ) == 0;
        }

        return 0;
    }

    bool operator != ( const String &s ) const
    {
        return !operator==( s );
    }

    bool operator > ( const String &s ) const
    {
        int i = 0;

        while ( i < len && i < s.len )
        {
            if ( buf[i] != s.buf[i] )
            {
                return buf[i] > s.buf[i];
            }

            ++i;
        }

        return 0;
    }

    bool operator >= ( const String &s )const
    {
        return !operator<( s );
    }

    bool operator < ( const String &s ) const
    {
        return !operator>( s ) && !operator==( s );
    }

    bool operator <= ( const String &s ) const
    {
        return !operator>( s );
    }

    String &operator + ( const String &s ) const
    {
        char *t = string_cat( buf, len, s.buf, s.len );
        String *u =  new String( t );
        delete[] t;

        return *u;
    }

    String &operator += ( const String &s )
    {
        String t = *this + s;

        buf = string_copy( buf, t.buf, t.len );
        len = t.len;
        return *this;
    }

    static char *string_cat( const char *left, int left_size,
                             const char *right, int right_size )
    {
        char *t = new char[left_size + right_size - 1];

        memcpy( t, left, left_size - 1 );
        memcpy( t + ( left_size - 1 ), right, right_size );

        return t;
    }

    static char *string_copy( char *target, const char *source, int length )
    {
        if ( target != source )
        {
            char *t = new char[length];
            memcpy( t, source, length );

            delete[] target;

            target = t;
        }

        return target;
    }

    static int string_length( const char *source )
    {
        int length;

        for ( length = 0; source[length] != 0; ++length )
        {
            // do nothing
        }

        return ++length;
    }

    static int string_index( const char *text, int text_size,
                             const char *pattern, int pattern_size )
    {
        // Horspool's algorithm without the shift table.
        int i = 0;
        int z = text_size - pattern_size;

        while ( i <= z )
        {
            char c = text[i + pattern_size - 1];

            if ( pattern[pattern_size - 1] == c &&
                    memcmp( pattern, text + i, pattern_size - 1 ) == 0 )
            {
                return i;
            }

            i++;
        }

        return -1;
    }

private:
    char *buf;
    int len;

    bool inBounds( int i )
    {
        return i >= 0 && i < len;
    }
};

ostream &operator << ( ostream &out, String str )
{
    str.print( out );
    return out;
}

istream &operator >> ( istream &in, String &str )
{
    str.read( in );
    return in;
}

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

    Spec( LeftLessThanRightByLength )
    {
        String i( "Hello" );
        String j( "Hello World" );
        bool result = i < j;
        Assert::That( result, Equals( 1 ) );
    }

    Spec( LeftLessThanRight )
    {
        String i( "Hello" );
        String j( "Hellp" );
        bool result = i < j;
        Assert::That( result, Equals( 1 ) );
    }

    Spec( LeftNotLessThanRight )
    {
        String i( "Hello" );
        String j( "Hello" );
        bool result = i < j;
        Assert::That( result, Equals( 0 ) );
    }

    Spec( LeftGreaterThanRightByLength )
    {
        String i( "Hello World" );
        String j( "Hello" );
        bool result = i > j;
        Assert::That( result, Equals( 1 ) );
    }

    Spec( LeftGreaterThanRight )
    {
        String i( "Hellp" );
        String j( "Hello" );
        bool result = i > j;
        Assert::That( result, Equals( 1 ) );
    }

    Spec( LeftNotGreaterThanRight )
    {
        String i( "Hello" );
        String j( "Hello" );
        bool result = i > j;
        Assert::That( result, Equals( 0 ) );
    }

    Spec( CompareEquivalentInstances )
    {
        String i( "Hello" );
        String j( "Hello" );
        bool result = ( i == j );
        Assert::That( result, Equals( 1 ) );
    }

    Spec( CompareDifferentInstances )
    {
        String i( "Hello" );
        String j( "Bye" );
        bool result = ( i != j );
        Assert::That( result, Equals( 1 ) );
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
