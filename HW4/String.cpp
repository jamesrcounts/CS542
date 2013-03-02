#include "String.h"

String::String( const char *s ): head( NULL )
{
    head = make_buffer( s );
}

String::String( const String &s ): head( NULL )
{
    head = copy_buffer( s.head );
}

String::~String()
{
    head = free_buffer( head );
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
    char *b = new char[buf_size];
    ListNode *result = NULL;

    while ( in.good() )
    {
        in.get( b, buf_size );

        if ( in.gcount() )
        {
            ListNode *t = make_buffer( b );
            delete[] b;
            ListNode *u = append_buffer( result, t );
            result = free_buffer( result );
            result = u;
            t = free_buffer( t );
        }
    }

    head = free_buffer( head );
    head = result;
}

String &String::operator = ( const String &s )
{
    ListNode *t = copy_buffer( s.head );
    head = free_buffer( head );
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
    w->head = free_buffer( w->head );
    w->head = copy_buffer( v );
    v = free_buffer( v );
    return *w;
}

String &String::operator += ( const String &s )
{
    String t = *this + s;
    head = free_buffer( head );
    head = copy_buffer( t.head );
    return *this;
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
