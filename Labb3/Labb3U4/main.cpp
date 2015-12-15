#include <iostream>
#include "Word.h"
#include "Dictionary.h"

using namespace std;

int main(){

Dictionary words;

    while(true){
        int val;
        cout << "MENY.\n1. Mata in en ny �vers�ttning.\n2. S�k efter en engelsk �vers�ttning.\n0. Exit" << endl;
        cin >> val;
        if(val == 1){   // L�gg in ett nytt svenskt ord plus engelsk �vers�ttning
            string sw, eng;
            cout << "Mata in det svenska ordet samt den engelska �vers�ttningen: ";
            cin >> sw;
            cin >> eng;
            words.addWord(sw,eng);
        }
        else if(val == 2){  // S�k efter den engelska �vers�ttningen
            cout << "Mata in det svenska ordet: ";
            char sw[80];
            cin >> sw;
            cout << words.getEngWord(sw) << endl;
        }else if(val == 0){
            return 0;
        }
    }
    return 0;
}
