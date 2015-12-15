#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include "Word.h"
#include <iostream>

using namespace std;

class Dictionary
{
    public:
        Dictionary();
        virtual ~Dictionary();
        void addWord(string sw, string eng);
        string getEngWord(string swedishWord);
    protected:
    private:
        std::vector<Word> words;
};

#endif // DICTIONARY_H
