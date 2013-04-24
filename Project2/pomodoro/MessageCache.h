#ifndef MESSAGECACHE_H
#define MESSAGECACHE_H

#include <deque>
#include <sstream>
#include <string>

class MessageCache
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