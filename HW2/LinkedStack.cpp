#include "LinkedStack.h"
void LinkedStack::push(char c){
	head = new CharLinkedListPair(c, head);
}

char LinkedStack::pop(){
	char c = head->info;
	CharLinkedListPair p = head;
	head = head->next;
	delete p;
	return c;
}

void LinkedStack::print (ostream & out)
{
	for(CharLinkedList p = head; p != 0; p = p->next)
	{
		out << p->info << ' ';
	}
}

~LinkedStack()
{
	CharLinkedList temp;
	for(CharLinkedList p = head; p != 0; )
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}