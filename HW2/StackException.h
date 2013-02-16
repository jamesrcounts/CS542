#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H
class StackException
{
    char * message;
public:
    StackException(char *msg)
        : message(msg)
    {

    }

    inline friend ostream & operator << (ostream & out, StackException & e)
    {
        return out << "StackException: " << e.message;
    }
};
#endif