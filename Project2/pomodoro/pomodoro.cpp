#include <iostream>
#include <string>
#include <unistd.h>
#include "Tomato.h"
using namespace std;

int main( int argc, char const *argv[] )
{
    Tomato pom;

    while ( 1 )
    {
        char input;
        string response;
        cout << pom.RecentMessages( ) << endl;
        cout << pom.Menu();

        while ( cin.get( input ) && input != ( char ) '\n' )
        {
            response.push_back( input );
        }

        Timer &t = pom.Next( response );

        while ( !t.IsExpired() )
        {
            cout << ".";
            cout.flush();
            sleep( 1 );
        }

        cout << endl;
    }

    return 0;
}