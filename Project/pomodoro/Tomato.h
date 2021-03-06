#ifndef TOMATO_H
#define TOMATO_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Menus.h"
#include "Timer.h"
#include "LogManager.h"

class Tomato
{
public:
    enum TomatoState { NEWTOMATO, BREAK, LOGGING, BACKTOWORK, };

    Tomato();
    std::string Menu();
    Timer &Next( std::string response = "" );
    std::string RecentMessages( unsigned long count );
    TomatoState State();
private:
    TomatoState state;
    Timer timer;
    std::ofstream out;
    Menus menu;
    LogManager logger;
};
#endif