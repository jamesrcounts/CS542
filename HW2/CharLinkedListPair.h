#ifndef CHARLINKEDLISTPAIR_H
#define CHARLINKEDLISTPAIR_H 
class CharLinkedListPair
{
public:
	char info;
	CharLinkedList next;
	CharLinkedListPair(char newInfo, CharLinkedList newNext) 
	:info(newInfo), next(newNext){

	}
};

typedef class CharLinkedListPair * CharLinkedList;
#endif	
