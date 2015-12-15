#include <iostream>
#include "Word.h"
#include "Dictionary.h"

using namespace std;

int main(){

Dictionary words;

    while(true){
        int val;
        cout << "MENY.\n1. Mata in en ny översättning.\n2. Sök efter en engelsk översättning.\n0. Exit" << endl;
        cin >> val;
        if(val == 1){   // Lägg in ett nytt svenskt ord plus engelsk översättning
            string sw, eng;
            cout << "Mata in det svenska ordet samt den engelska översättningen: ";
            cin >> sw;
            cin >> eng;
            words.addWord(sw,eng);
        }
        else if(val == 2){  // Sök efter den engelska översättningen
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
