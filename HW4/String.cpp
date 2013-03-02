#include "String.h"

String::String( const char *s ): head( NULL ), len( 0 ), buf( NULL )
{
    head = make_buffer( s );
}

String::String( const String &s ): head( NULL ), len( 0 ), buf( NULL )
{
    head = copy_buffer( s.head );
}

int String::length() const
{
    int i = 0;

    for ( ListNode *it = head; it != NULL; it = it->next )
    {
        ++i;
    }

    return i;
}

int String::indexOf( const char c ) const
{
    int i = 0;

    for ( ListNode *it = head; it != NULL; it = it->next )
    {

        if ( it->info == c )
        {
            return i;
        }

        ++i;
    }

    return -1;
}

void String::print( ostream &out )
{
    for ( ListNode *it = head; it != NULL; it = it->next )
    {
        out.put( it->info );
    }
}

void String::read( istream &in )
{
    int buf_size = 1024;
    char *buffer = new char[buf_size];
    int result_size = 0;
    char *result = new char[result_size];

    while ( in.good() )
    {
        in.get( buffer, buf_size );
        int last_read = in.gcount();

        if ( last_read )
        {
            char *t = result;
            result = new char[result_size + last_read];
            memcpy( result, t, result_size );
            memcpy( result + result_size, buffer, last_read );
            result_size += last_read;
            delete[] t;
        }
    }

    char terminator[1] = {0};
    char *s = result;
    result = new char[result_size + 1];
    memcpy( result, s, result_size );
    memcpy( result + result_size, terminator, 1 );
    ++result_size;
    delete[] s;

    ListNode *b = make_buffer( result );
    free_buffer( head );
    head = b;

    delete[] result;
}

String::~String()
{
    delete[] buf;
}

String &String::operator = ( const String &s )
{
    buf = string_copy( buf, s.buf, s.len );
    len = s.len;

    ListNode *t = copy_buffer( s.head );
    free_buffer( head );
    head = t;

    return *this;
}

char &String::operator []( int index )
{
    assert( inBounds( index ) );
    ListNode *t = head;

    for ( int i = index; 0 <= i; --i )
    {
        t = t->next;
    }

    return t->info;
}

bool String::operator == ( const String &s ) const
{
    ListNode *self ;
    ListNode *other ;

    for ( self = head, other = s.head;
            self != NULL && other != NULL && self->info == other->info;
            self = self->next, other = other->next )
    {
    }

    return self == other;
}

String &String::operator + ( const String &s ) const
{
    ListNode *v = append_buffer( head, s.head );
    String *w = new String();
    w->head = v;
    return *w;
}

String &String::operator += ( const String &s )
{
    String t = *this + s;

    buf = string_copy( buf, t.buf, t.len );
    len = t.len;
    head = t.head;
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
    return i >= 0 && i < length();
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
