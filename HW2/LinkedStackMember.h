#ifndef LINKEDSTACKMEMBER_H
#define LINKEDSTACKMEMBER_H 1

typedef class LinkedStackMember * LinkedStackNode;
class LinkedStackMember
{
public:
    char value;
    LinkedStackNode next;
    LinkedStackMember( char c, LinkedStackNode n )
        : value( c ), next( n )
    {
    }
};
#endif