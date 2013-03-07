#include <sstream>
#include "Snake.h"

Snake::Snake()
{
    stride = 5;
}

void Snake::Move()
{
    stringstream buffer;
    buffer << "Slithering... " << stride << "m." << endl;
    WriteToLog( buffer.str() );
}
