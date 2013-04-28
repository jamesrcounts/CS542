#ifndef TOMATO_H
#define TOMATO_H

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "FileListener.h"
#include "LogManager.h"
#include "Menus.h"
#include "MessageCache.h"
#include "Timer.h"

class Tomato
{
public:
    enum TomatoState { NEWTOMATO, BREAK, LOGGING, BACKTOWORK, };

    Tomato();
    std::string Menu();
    Timer &Next( std::string response = "" );
    std::string RecentMessages();
    TomatoState State();
private:
    TomatoState state;
    Timer timer;
    FileListener out;
    Menus menu;
    LogManager logger;
    MessageCache cache;
};
#endif