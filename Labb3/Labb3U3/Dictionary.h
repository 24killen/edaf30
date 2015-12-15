#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include "Word.h"


class Dictionary
{
    public:
        Dictionary();
        virtual ~Dictionary();
        void addWord(const char* sw, const char* eng);
        const char* getEngWord(const char* swedishWord);
    protected:
    private:
        std::vector<Word> words;
};

#endif // DICTIONARY_H
