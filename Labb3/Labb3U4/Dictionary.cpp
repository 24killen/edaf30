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

void Dictionary::addWord(string sw, string eng){
    words.push_back(Word(sw,eng));
}

string Dictionary::getEngWord(string swedishWord){
     int lenght = words.size();
     for(int i=0; i<lenght;++i){
        if(words[i].get_sw().compare(swedishWord) == 0){
            return words[i].get_eng();
        }
     }
     cout << "No match!" <<endl;
     return swedishWord; // Returnerar samma ord som input i stället för 0. 0 hänger programmet.
}
