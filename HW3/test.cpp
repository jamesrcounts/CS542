/***************************************************
test.cpp

Jim Counts
CS 542 - OO
Homework 3
**************************************************/

#include <igloo/igloo.h>
#include <arpa/inet.h>
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

    String &operator = ( const String &s )
    {
        buf = string_copy( buf, s.buf, s.len );
        len = s.len;

        return *this;
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

    /*public:
        /// Both constructors should construct
        /// this String from the parameter s
        char &operator []( int index );
        int size();
        String reverse(); // does not modify this String
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
        bool inBounds( int i )
        {
            return i >= 0 && i < len;
        }
        */
};
ostream &operator << ( ostream &out, String str );
istream &operator >> ( istream &in, String &str );

int main()
{
    return TestRunner::RunAllTests();
}

/*
As a String object
I want my assignment operator to do a deep copy
So that I can get my value by assignment.
*/
Context( InitializeByAssignment )
{
    String *source;
    String *target;

    // cppcheck-suppress unusedFunction
    void SetUp()
    {
        source = NULL;
        source = new String( "Hello World" );

        target = NULL;
        target = new String( "Goodbye" );

        *target = *source;
    };

    // cppcheck-suppress unusedFunction
    void TearDown()
    {
        delete source;
        delete target;
    };

    Spec( GivenAString )
    {
        Assert::That( ( int )source, !Equals( NULL ) );
    }

    Spec( AndGivenASecondString )
    {
        Assert::That( ( int )target, !Equals( NULL ) );
    }

    Spec( WhenIAssignTheFirstToTheSecond )
    {
        Assert::That( target->c_str(), Equals( source->c_str() ) );
    }

    Spec( ThenMySecondStringShouldStillBeSeparateInstances )
    {
        Assert::That( ( int ) source, !Equals( ( int ) target ) );

    }
};

/*
As a String object
I want to initialize myself from another String
So that I can be constructed
*/
Context( InitializeFromString )
{
    String *source;
    String *received;

    // cppcheck-suppress unusedFunction
    void SetUp()
    {
        source = NULL;
        source = new String( "Hello World" );

        received = NULL;
        received = new String( *source );
    }

    // cppcheck-suppress unusedFunction
    void TearDown()
    {
        delete source;
        delete received;
    }

    Spec( GivenAString )
    {
        Assert::That( ( int )source, !Equals( NULL ) );
    }

    Spec( WhenIConstructAString )
    {
        Assert::That( ( int )received, !Equals( NULL ) );
    }

    Spec( ThenMyStringShouldRepresentTheSameData )
    {
        Assert::That( received->c_str(), Equals( source->c_str() ) );
    }
};

/*
As a String object
I want to initialize myself from a CStr
So that I can be constructed
*/
Context( InitializeFromCStr )
{
    string hello;
    const char *cvalue;
    String *received;

    // cppcheck-suppress unusedFunction
    void SetUp()
    {
        hello = "Hello World";
        cvalue = hello.c_str();
        received = NULL;

        received = new String( cvalue );
    }

    // cppcheck-suppress unusedFunction
    void TearDown()
    {
        delete received;
    }

    Spec( GivenACStr )
    {
        Assert::That( cvalue, Equals( hello ) );
    }

    Spec( WhenIConstructAString )
    {
        Assert::That( ( int )received, !Equals( NULL ) );
    }

    Spec( ThenMyStringShouldRepresentTheSameData )
    {
        Assert::That( received->c_str(), Equals( hello ) );
    }
};