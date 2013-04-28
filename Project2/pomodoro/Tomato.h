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

    Tomato( LogManager &log );
    std::string Menu();
    Timer &Next( std::string response = "" );
    TomatoState State();
private:
    TomatoState state;
    Timer timer;
    Menus menu;
    LogManager *logger;
};
#endif