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

    int len; // deprecated
    char *buf;  // deprecated
    const char *c_str(); // deprecated

    static ListNode *append_buffer( const ListNode *left, const ListNode *right )
    {
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

    static void free_buffer( ListNode *c )
    {
        if ( c == NULL )
        {
            return;
        }

        free_buffer( c->next );
        delete c;
    }


    static ListNode *make_buffer( const char *source )
    {
        if ( source[0] == 0 )
        {
            return NULL;
        }

        return new ListNode( source[0], make_buffer( source + 1 ) );
    }

    static char *string_cat( const char *left, int left_size,
                             const char *right, int right_size );
    static char *string_copy( char *target, const char *source, int length );
    static int string_length( const char *source );
    static int string_index( const char *text, int text_size,
                             const char *pattern, int pattern_size );
};

ostream &operator << ( ostream &out, String str );
istream &operator >> ( istream &in, String &str );

#endif