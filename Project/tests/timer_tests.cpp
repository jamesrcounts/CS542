#include <igloo/igloo.h>
#include <approvals/Approvals.h>
#include <Timer.h>

using namespace igloo;

Context( DescribeATimer )
{
    Spec( ItTellsYouWhenAnIntervalExpires )
    {
        Timer t( 10, 0 );
        Assert::That( t.IsExpired( 11 ), Equals( true ) );
    }

    Spec( ItTellsYouWhenTheIntervalHasNotExpired )
    {
        Timer t( 60, 0 );
        Assert::That( t.IsExpired( 30 ), Equals( false ) );
    }

    Spec( ItBeginsAtTheCurrentTimeByDefault )
    {
        Timer t( 10 );
        Assert::That( t.IsExpired( time( NULL ) + 10 ), Equals( true ) );
    }

    Spec( ItChecksTheCurrentTimeByDefault )
    {
        Timer t( 1 );
        sleep( 1 );
        Assert::That( t.IsExpired(), Equals( true ) );
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