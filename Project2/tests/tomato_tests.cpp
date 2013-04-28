#include <igloo/igloo.h>
#include <approvals/Approvals.h>
#include <Tomato.h>

using namespace igloo;

Context( DescribeATomato )
{
    Spec( ItStartsInTheNewTomatoState )
    {
        LogManager lm;
        Tomato t( lm );
        Assert::That( t.State(), Equals( Tomato::NEWTOMATO ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesToLoggingAfterNew )
    {
        LogManager lm;
        Tomato t( lm );
        t.Next();
        Assert::That( t.State(), Equals( Tomato::LOGGING ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesToBreakAfterLogging )
    {
        LogManager lm;
        Tomato t( lm );
        t.Next();
        t.Next();
        Assert::That( t.State(), Equals( Tomato::BREAK ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesBackToWorkAfterBreak )
    {
        LogManager lm;
        Tomato t( lm );
        t.Next();
        t.Next();
        t.Next( "1" );
        Assert::That( t.State(), Equals( Tomato::BACKTOWORK ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesToLoggingAfterWork )
    {
        LogManager lm;
        Tomato t( lm );
        t.Next();
        t.Next();
        t.Next( "1" );
        t.Next();
        Assert::That( t.State(), Equals( Tomato::LOGGING ) );
        Approvals::Verify( t.Menu() );
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