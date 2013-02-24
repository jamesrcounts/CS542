#include "String.h"

String::String( const char *s )
{
    buf = NULL;
    len = string_length( s );
    buf = string_copy( buf, s, len );
}

String::String( const String &s )
{
    buf = NULL;
    buf = string_copy( buf, s.buf, s.len );
    len = s.len;
}

int String::indexOf( char c )
{
    char t[2] = {c, 0};
    return string_index( buf, size(), t, 1 );
}

int String::indexOf( String pattern )
{
    return string_index( buf, size(), pattern.buf, pattern.size() );
}

void String::print( ostream &out )
{
    out << buf;
}

void String::read( istream &in )
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

String String::reverse()
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

int String::size()
{
    return len - 1;
}

const char *String::c_str()
{
    return buf;
}

String::~String()
{
    delete[] buf;
}

String &String::operator = ( const String &s )
{
    buf = string_copy( buf, s.buf, s.len );
    len = s.len;

    return *this;
}

char &String::operator []( int index )
{
    assert( inBounds( index ) );
    return buf[index];
}

bool String::operator == ( const String &s ) const
{
    if ( len == s.len )
    {
        return memcmp( buf, s.buf, len ) == 0;
    }

    return 0;
}

bool String::operator != ( const String &s ) const
{
    return !operator==( s );
}

bool String::operator > ( const String &s ) const
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

bool String::operator >= ( const String &s )const
{
    return !operator<( s );
}

bool String::operator < ( const String &s ) const
{
    return !operator>( s ) && !operator==( s );
}

bool String::operator <= ( const String &s ) const
{
    return !operator>( s );
}

String &String::operator + ( const String &s ) const
{
    char *t = string_cat( buf, len, s.buf, s.len );
    String *u =  new String( t );
    delete[] t;

    return *u;
}

String &String::operator += ( const String &s )
{
    String t = *this + s;

    buf = string_copy( buf, t.buf, t.len );
    len = t.len;
    return *this;
}

char *String::string_cat( const char *left, int left_size,
                          const char *right, int right_size )
{
    char *t = new char[left_size + right_size - 1];

    memcpy( t, left, left_size - 1 );
    memcpy( t + ( left_size - 1 ), right, right_size );

    return t;
}

char *String::string_copy( char *target, const char *source, int length )
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

int String::string_length( const char *source )
{
    int length;

    for ( length = 0; source[length] != 0; ++length )
    {
        // do nothing
    }

    return ++length;
}

int String::string_index( const char *text, int text_size,
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

bool String::inBounds( int i )
{
    return i >= 0 && i < len;
}

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
