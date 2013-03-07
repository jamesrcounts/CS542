#include <sstream>
#include "Alien.h"

Alien::Alien()
{
    stride = 1000;
}

void Alien::Move()
{
    stringstream buffer;
    buffer << "Teleporting... " << stride << "ly." << endl;
    WriteToLog( buffer.str() );
}
