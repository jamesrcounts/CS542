#ifndef STRING_H
#define STRING_H

#include <assert.h>
#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String( const char *s = "" );

    String( const String &s );

    int indexOf( char c );

    int indexOf( String pattern );

    void print( ostream &out );

    void read( istream &in );

    String reverse();

    int size();

    const char *c_str();

    ~String();

    String &operator = ( const String &s );

    char &operator []( int index );

    bool operator == ( const String &s ) const;

    bool operator != ( const String &s ) const;

    bool operator > ( const String &s ) const;

    bool operator >= ( const String &s )const;

    bool operator < ( const String &s ) const;

    bool operator <= ( const String &s ) const;

    String &operator + ( const String &s ) const;

    String &operator += ( const String &s );

    static char *string_cat( const char *left, int left_size,
                             const char *right, int right_size );

    static char *string_copy( char *target, const char *source, int length );

    static int string_length( const char *source );

    static int string_index( const char *text, int text_size,
                             const char *pattern, int pattern_size );

private:
    char *buf;
    int len;

    bool inBounds( int i );
};

ostream &operator << ( ostream &out, String str );

istream &operator >> ( istream &in, String &str );

#endif