#ifndef MESSAGECACHE_H
#define MESSAGECACHE_H

#include <deque>
#include <sstream>
#include <string>
#include "LogListener.h"

class MessageCache : public LogListener
{
public:
    MessageCache( int size );
    void Insert( std::string message );
    std::string Messages();
private:
    int max;
    std::deque<std::string> cache;
};
#endif