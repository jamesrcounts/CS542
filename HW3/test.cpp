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
        for ( len = 0; s[len] != 0; len++ )
        {
            // do nothing
        }

        buf = new char[len];
        memcpy( buf, s, len );
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
        String( const String &s );
        String operator = ( const String &s );
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
        received = 0;

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
        Assert::That( ( int )received, !Equals( 0 ) );
    }

    Spec( ThenMyStringShouldRepresentTheSameData )
    {
        Assert::That( received->c_str(), Equals( hello ) );
    }
};