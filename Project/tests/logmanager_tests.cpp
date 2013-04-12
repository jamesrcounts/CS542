#include <igloo/igloo.h>
#include <approvals/Approvals.h>
#include <LogManager.h>
#include <Timer.h>
#include <string>
#include <sstream>

using namespace igloo;
using namespace std;

Context( DescribeALogManager )
{
    Spec( ItWritesMessages )
    {
        stringstream logout;
        Timer t( 10, 0 );
        t.IsExpired( 25 * 60 );

        LogManager l;
        l.AddListener( logout );
        l.Log( t, "Hello World" );
        Approvals::Verify( logout.str() );
    }

    Spec( ItPlaysBackRecentMessages )
    {
        LogManager l;

        for ( int i = 0; i < 10; ++i )
        {
            Timer t( 10, 10 * i );

            if ( t.IsExpired( 10 * ( i + 1 ) ) )
            {
                string s;
                s.push_back( char( i + 33 ) );
                l.Log( t, s );
            }
        }

        Approvals::Verify( l.RecentMessages( 5 ) );
    }
};

int main( int argc, char const *argv[] )
{
    DefaultTestResultsOutput output;
    TestRunner runner( output );

    IglooMetadataListener listener;
    runner.AddListener( &listener );
    MinimalProgressTestListener mpl;
    runner.AddListener( &mpl );

    return runner.Run();
}