#include "Dictionary.h"
#include "Word.h"
#include <vector>;
#include <iostream>
#include <cstring>

using namespace std;

Dictionary::Dictionary(){

}

Dictionary::~Dictionary(){

}

void Dictionary::addWord(const char* sw, const char* eng){
    words.push_back(Word(sw,eng));
}

 const char* Dictionary::getEngWord(const char* swedishWord){
     int lenght = words.size();
     for(int i=0; i<lenght;++i){
        if(strcmp(words[i].get_sw(),swedishWord) == 0){
            return words[i].get_eng();
        }else{
        }
     }
     cout << "No match!" <<endl;
     return swedishWord; // Returnerar samma ord som input i stället för 0. 0 hänger programmet.
}
