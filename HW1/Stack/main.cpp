/***************************************************
main.cpp

Jim Counts
CS 542 - OO
Homework 1
**************************************************/

#include <iostream>
#include "Stack.h"

using namespace std;

/*
The main entry point for the program.
*/
int main (int argc, const char * argv[])
{
	char input;
	Stack s;
	
	while(!cin.eof())
	{
		cout << "Please enter a string without spaces." << endl;
		while(cin.get(input) && input != (char)'\n')
		{			
			s.push(input);	
		}

		while(!s.isEmpty())
		{
			cout << s.top();
			s.pop();
		}

		cout << endl;		
	}
}
