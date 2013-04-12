#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Timer.h"

class LogManager
{
private:
    std::vector<std::string> cache;
    std::vector<std::ostream *> listeners;
public:
    void AddListener( std::ostream &out );
    void Log( const Timer &t, const std::string &message );
    std::string RecentMessages( unsigned long count );
};
#endif