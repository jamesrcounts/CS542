#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H 

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

class WordCounter
{
private:
    std::map<std::string, int> wc;
    std::vector<std::string> ex;
    std::string erase_punctuation(std::string s);
public:
    void count( std::istream &in );
    int countOf( std::string word );
    void mustExclude( std::istream &in );
    void print( std::ostream &out );
    friend std::ostream &operator<<( std::ostream &out, WordCounter &it )
    {
        it.print( out );
        return out;
    }
};

#endif