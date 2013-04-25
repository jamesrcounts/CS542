#include "Tomato.h"

using namespace std;

Tomato::Tomato()
    : state( NEWTOMATO ),
      timer( 0 ),
      out( "Tomato.txt", ofstream::out ),
      cache( 5 )
{
    logger.AddListener( cache );
};

Timer &Tomato::Next( string response )
{
    switch ( state )
    {
    case BACKTOWORK:
    case NEWTOMATO:
        state = LOGGING;
        timer = Timer( 25 );
        break;
    case LOGGING:
        state = BREAK;
        logger.Log( timer, response );
        timer = Timer( 0 );
        break;
    case BREAK:
        int i = atoi( response.c_str() );
        int bt = 0;

        if ( i < 1 || 4 < i )
        {
            cout << "Don't understand. Try again." << endl;
            break;
        }
        else
        {
            switch ( i )
            {
            case 1:
                bt = 5;
                break;
            case 2:
                bt = 10;
                break;
            case 3:
                bt = 15;
                break;
            case 4:
                bt = 25;
                break;
            }
        }

        state = BACKTOWORK;
        timer = Timer( bt );
        break;
    }

    return timer;
}

string Tomato::Menu()
{
    string menu_text;

    switch ( state )
    {
    case NEWTOMATO:
        menu_text = menu.MainMenu();
        break;
    case LOGGING:
        menu_text = menu.TomatoFinishedMenu();
        break;
    case BACKTOWORK:
        menu_text = menu.BackToWorkMenu();
        break;
    case BREAK:
        menu_text = menu.BreakMenu();
        break;
    }

    return  menu_text;
}

string Tomato::RecentMessages( )
{
    return cache.Messages( );
}

Tomato::TomatoState Tomato::State()
{
    return state;
}