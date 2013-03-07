#include <sstream>
#include "Horse.h"

Horse::Horse()
{
    stride = 45;
}

void Horse::Move()
{
    stringstream buffer;
    buffer << "Galloping... " << stride << "m." << endl;
    WriteToLog( buffer.str() );
}
