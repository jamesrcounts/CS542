/***************************************************
main.cpp

Jim Counts
CS 542 - OO
Homework 1
**************************************************/

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

/*
The main entry point for the program.
*/
int main (int argc, const char * argv[])
{
	string input;
	Stack s;
	while(1)
	{

		cout << "Please enter a string without spaces." << endl;
		cin >> input;
		
		for (
			string::iterator it = input.begin();
			it != input.end();
			++it)
		{
			s.push(*it);
		}

		while(!s.isEmpty())
		{
			cout << s.top();
			s.pop();
		}

		cout << endl;
	}
}