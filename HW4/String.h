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
    int indexOf( const char c ) const;
    int length() const;
    void print( ostream &out );
    void read( istream &in );
    ~String();

    String &operator = ( const String &s );
    char &operator []( const int index );
    bool operator == ( const String &s ) const;
    String &operator + ( const String &s ) const;
    String &operator += ( const String &s );

private:
    bool inBounds( int i );
    struct ListNode
    {
        char info;
        ListNode *next;
        ListNode( char newInfo, ListNode *newNext )
            : info( newInfo ), next( newNext )
        {
        }
    };
    ListNode *head;

    static ListNode *append_buffer( const ListNode *left, const ListNode *right )
    {
        if ( left == NULL )
        {
            return copy_buffer( right );
        }

        if ( left->next == NULL )
        {
            ListNode *t;
            t = copy_buffer( right );
            return new ListNode( left->info, t );
        }

        return new ListNode( left->info, append_buffer( left->next, right ) );
    }

    static ListNode *copy_buffer( const ListNode *source )
    {
        if ( source == NULL )
        {
            return NULL;
        }

        return new ListNode( source->info, copy_buffer( source->next ) );
    }

    static ListNode *free_buffer( ListNode *c )
    {
        for ( ListNode *it = c; it != NULL; )
        {
            c = it;
            it = it->next;
            delete c;
        }

        return NULL;
    }


    static ListNode *make_buffer( const char *source )
    {
        if ( source[0] == 0 )
        {
            return NULL;
        }

        return new ListNode( source[0], make_buffer( source + 1 ) );
    }
};

ostream &operator << ( ostream &out, String str );
istream &operator >> ( istream &in, String &str );

#endif