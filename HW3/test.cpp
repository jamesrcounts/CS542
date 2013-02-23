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

    String reverse()
    {
        char *reversed = new char[len];

        int i = 0;
        int j = len - 2;

        while ( i < len )
        {
            reversed[i++] = buf[j--];
        }

        reversed[len] = 0;
        String *r = new String( reversed );
        return *r;
    }

    int size()
    {
        return len - 1;
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


    static int string_length( const char *source )
    {
        int length;

        for ( length = 0; source[length] != 0; ++length )
        {
            // do nothing
        }

        return ++length;
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

    ~String()
    {
        delete[] buf;
    }

    const char *c_str()
    {
        return buf;
    }
private:
    char *buf;
    int len;

    bool inBounds( int i )
    {
        return i >= 0 && i < len;
    }

    /*public:
        int indexOf( char c );
        int indexOf( String pattern );
        bool operator == ( String s );
        bool operator != ( String s );
        bool operator > ( String s );
        bool operator < ( String s );
        bool operator <= ( String s );
        bool operator >= ( String s );
        /// concatenates this and s to return result
        String operator + ( String s );
        /// concatenates s onto end of this
        String operator += ( String s );
        void print( ostream &out );
        void read( istream &in );
    private:
        */
};
ostream &operator << ( ostream &out, String str );
istream &operator >> ( istream &in, String &str );

int main()
{
    return TestRunner::RunAllTests();
}

Context( UsingStringFunctions )
{
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
