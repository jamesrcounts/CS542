#include "Timer.h"

Timer::Timer( int seconds, time_t now ) : duration( seconds ), start( now )
{}

bool Timer::IsExpired( time_t now )
{
    return ( start + duration ) <= now;
}