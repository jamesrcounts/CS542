#include "Animal.h"
void Animal::WriteToLog( string message )
{
    *logger << message;
}
void Animal::UseSpy( ostream &spy )
{
    logger = &spy;
}
