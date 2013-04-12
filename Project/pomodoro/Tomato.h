#ifndef TOMATO_H
#define TOMATO_H

#include <string>
#include "Menus.h"
#include "Timer.h"

class Tomato
{
public:
    enum TomatoState { NEWTOMATO, WORKING, BREAK, LOGGING, BACKTOWORK, };

    Tomato();
    std::string Menu();
    Timer &Next();
    TomatoState State();
private:
    TomatoState state;
    Timer timer;
    Menus menu;
};
#endif