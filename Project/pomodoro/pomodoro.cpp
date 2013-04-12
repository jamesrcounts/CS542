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
        cout << pom.Menu();
        cin.get();
        Timer &t = pom.Next();

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