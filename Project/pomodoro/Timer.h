#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
private:
    int duration;
    time_t start;
public:
    Timer( int seconds, time_t now = time( NULL ) );

    bool IsExpired( time_t now = time( NULL ) );
};
#endif