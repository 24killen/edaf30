#include "Word.h"
#include <cstring>
#include <iostream>

using namespace std;

Word::Word(string sw, string eng){
    swedish = sw;
    english = eng;
}

Word::~Word(){

}

string Word::get_sw(){
    return swedish;
}

string Word::get_eng(){
    return english;
}
