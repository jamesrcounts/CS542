/* test.cpp */

#include <iostream>
#include <igloo/igloo.h>
#include <sstream>
#include <string>

using namespace std;
using namespace igloo;

class Animal
{
private:
    ostream *logger;
protected:
    int stride;
    void WriteToLog( string message )
    {
        *logger << message;
    }
    Animal():  logger( &cout ), stride( 1 ) {}
public:
    virtual ~Animal() {};
    virtual void Move() = 0;
    void UseSpy( ostream &spy )
    {
        logger = &spy;
    }
};

class Snake : public Animal
{
public:
    Snake()
    {
        stride = 5;
    }
    ~Snake() {}
    void Move()
    {
        stringstream buffer;
        buffer << "Slithering... " << stride << "m." << endl;
        WriteToLog( buffer.str() );
    }

};

class Horse : public Animal
{
public:
    Horse()
    {
        stride = 45;
    }

    void Move()
    {
        stringstream buffer;
        buffer << "Galloping... " << stride << "m." << endl;
        WriteToLog( buffer.str() );
    }

};

class Alien : public Animal
{
public:
    Alien()
    {
        stride = 1000;
    }

    void Move()
    {
        stringstream buffer;
        buffer << "Teleporting... " << stride << "ly." << endl;
        WriteToLog( buffer.str() );
    }
};

Context( DescribeASnake )
{
    Spec( ItSlithers )
    {
        string expected( "Slithering... 5m.\n" );
        stringstream spy;
        Snake s;
        s.UseSpy( spy );
        s.Move();
        Assert::That( spy.str(), Equals( expected ) );
    }
};

Context( DescribeAHorse )
{
    Spec( ItGallops )
    {
        string expected( "Galloping... 45m.\n" );
        stringstream spy;
        Horse h;
        h.UseSpy( spy );
        h.Move();
        Assert::That( spy.str(), Equals( expected ) );
    }
};

Context( DescribeAnAlien )
{
    Spec( ItTeleports )
    {
        string expected( "Teleporting... 1000ly.\n" );
        stringstream spy;
        Alien a;
        a.UseSpy( spy );
        a.Move();
        Assert::That( spy.str(), Equals( expected ) );
    }
};

Context( DescribeAGroupOfAnimals )
{
    Spec( TheyCanMove )
    {
        string expected( "Slithering... 5m.\n" );
        expected += "Galloping... 45m.\n";
        expected += "Teleporting... 1000ly.\n";

        vector<Animal *> group;
        group.push_back( new Snake() );
        group.push_back( new Horse() );
        group.push_back( new Alien() );

        stringstream spy;

        for ( vector<Animal *>::iterator it = group.begin();
                it != group.end();
                ++it )
        {
            Animal *a = *it;
            a->UseSpy( spy );
            a->Move();
        }

        Assert::That( spy.str(), Equals( expected ) );

        for ( vector<Animal *>::iterator it = group.begin();
                it != group.end();
                ++it )
        {
            delete *it;
        }
    }
};

int main( )
{
    return TestRunner::RunAllTests();
}