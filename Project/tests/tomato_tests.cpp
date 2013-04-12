#include <igloo/igloo.h>
#include <approvals/Approvals.h>
#include <Tomato.h>

using namespace igloo;

Context( DescribeATomato )
{
    Spec( ItStartsInTheNewTomatoState )
    {
        Tomato t;
        Assert::That( t.State(), Equals( Tomato::NEWTOMATO ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesToLoggingAfterNew )
    {
        Tomato t;
        t.Next();
        Assert::That( t.State(), Equals( Tomato::LOGGING ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesToBreakAfterLogging )
    {
        Tomato t;
        t.Next();
        t.Next();
        Assert::That( t.State(), Equals( Tomato::BREAK ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesBackToWorkAfterBreak )
    {
        Tomato t;
        t.Next();
        t.Next();
        t.Next();
        Assert::That( t.State(), Equals( Tomato::BACKTOWORK ) );
        Approvals::Verify( t.Menu() );
    }

    Spec( ItGoesToLoggingAfterWork )
    {
        Tomato t;
        t.Next();
        t.Next();
        t.Next();
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