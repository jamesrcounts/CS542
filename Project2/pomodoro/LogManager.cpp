#include "LogManager.h"

using namespace std;

void LogManager::AddListener( ostream &out )
{
    listeners.push_back( &out );
}
void LogManager::Log( const Timer &t, const string &message )
{
    stringstream full_message;
    full_message << Timer::Format( t ) << " " << message << endl;

    // cache.push_back( full_message.str() );

    for ( std::vector<ostream *>::iterator it = listeners.begin();
            it != listeners.end();
            ++it )
    {
        **it << full_message.str() << endl;
    }
}

// string LogManager::RecentMessages( unsigned long count )
// {
//     stringstream recent( "" );

//     // unsigned long i = 0;

//     // for ( std::vector<std::string>::reverse_iterator rit = cache.rbegin();
//     //         rit != cache.rend() && i < count;
//     //         ++rit, ++i )
//     // {
//     //     recent << *rit;
//     // }

//     return recent.str();
// }