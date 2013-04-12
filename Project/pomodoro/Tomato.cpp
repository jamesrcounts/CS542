#include "Tomato.h"

using namespace std;

Tomato::Tomato() : state( NEWTOMATO ), timer( 0 ) {};

Timer &Tomato::Next()
{
    switch ( state )
    {
    case BACKTOWORK:
    case NEWTOMATO:
        state = LOGGING;
        timer = Timer( 25 );
        break;
    case WORKING:
        state = LOGGING;
        break;
    case LOGGING:
        state = BREAK;
        timer = Timer( 0 );
        break;
    case BREAK:
        state = BACKTOWORK;
        timer = Timer( 5 );
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
    case WORKING:
        break;
    }

    return menu_text;
}

Tomato::TomatoState Tomato::State()
{
    return state;
}