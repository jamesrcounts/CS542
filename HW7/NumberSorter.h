#ifndef NUMBERSORTER_H
#define NUMBERSORTER_H 

#include <vector>
#include <iostream>

class NumberSorter
{
private:
    bool sorted;
    std::vector<int> ns;
public:
    NumberSorter();
    void read( std::istream &in );
    void sort();
    void print( std::ostream &out );
    void print_even( std::ostream &out );
    void print_odd( std::ostream &out );
};

#endif