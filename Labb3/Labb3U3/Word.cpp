#include "Word.h"
#include <cstring>

Word::Word(const char *sw, const char *eng){
    swedish = new char [strlen(sw)+1];
    strcpy(swedish,sw);
    english = new char [strlen(eng)+1];
    strcpy(english, eng);
}

Word::~Word(){
    delete &swedish, &english;
}

const char* Word::get_sw()const{
    return swedish;
}

const char* Word::get_eng()const{
    return english;
}
