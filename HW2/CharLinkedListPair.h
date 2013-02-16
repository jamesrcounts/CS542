#ifndef CHARLINKEDLISTPAIR_H
#define CHARLINKEDLISTPAIR_H
typedef class CharLinkedListPair * CharLinkedList;
class CharLinkedListPair
{
public:
    char info;
    CharLinkedList next;
    CharLinkedListPair(char newInfo, CharLinkedList newNext)
        : info(newInfo), next(newNext)
    {}
};
#endif