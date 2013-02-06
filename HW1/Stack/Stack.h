#define STACK_CAPACITY 1000
#include <exception>

using namespace std;

/*
An exception indicating that an item could not be added
to a stack because the stack was full.
*/
class StackOverflowException : public exception
{
	virtual const char* what() const throw()
	{
		return "Could not add another item because the stack was already full.";
	}	
} soex;

/*
An exception indicating that an item could not be returned
from the stack because the stack was empty.
*/
class StackUnderflowException : public exception
{
	virtual const char* what() const throw()
	{
		return "Could not return an item because the stack is empty.";
	}
} suex;

class Stack
{
private:
	char items[STACK_CAPACITY];
	int last;
public:
	/*
	Initializes a new instance of the stack class.
	*/
	Stack()
	{
		last = -1;
		for(int i = 0; i < STACK_CAPACITY; i++)
		{
			items[i] = 0;
		}
	}	
	
	/*
	Adds the character specified by the parameter 'c' to the 
	top of the stack.
	*/
	void push( char c )
	{
		if(last == STACK_CAPACITY)
		{
			throw soex;
		}

		items[++last] = c;		
	}
	 
	/*
	Removes the top element
	*/
	void pop()
	{
		if (!isEmpty())
		{
			last--;
		}
	}

	/*
	Returns the top element.
	*/
	char top()
	{
		if(isEmpty())
		{
			throw suex;
		}

		return items[last];
	}

	/*
	Returns true iff the stack is empty.
	*/
	bool isEmpty()
	{
		return (last < 0);
	}

	/*
	Class destructor.
	*/
	~Stack()
	{
		/* nothing to do */
	}
};