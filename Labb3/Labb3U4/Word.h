#ifndef WORD_H
#define WORD_H
#include <iostream>

using namespace std;

class Word{
    public:
        Word(const Word &w): Word(w.swedish, w.english){};      //Copy-konstruktor
        Word(string sw, string eng);                            //Konstruktor
        virtual ~Word();                                        //Destruktor
        string get_sw();
        string get_eng();
    protected:
    private:
        string swedish;
        string english;
};

#endif // WORD_H
