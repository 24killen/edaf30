#include <iostream>
#include "Mynt.h"
#include <array>

using namespace std;

int main(){
// a)
    cout << "Uppgift a: " << endl;
    Mynt m;
    int indata = -100;
    while(indata!=0){
        cout << "Mata in antal kast:";
        cin >> indata;
        for(int i  = 0; i < indata; i++){
            m.kasta();
            m.visa();
        }
        cout << endl;
    }

//b)
    cout << endl << "Uppgift b: " << endl;
    int antalKast, counter = 0;
    Mynt m1, m2;
    cout << "Mata in antal kast:";
    cin >> antalKast;

    for(int i = 0; i<antalKast;++i){
        m1.kasta();
        m2.kasta();
        //cout << "Mynt 1: " << m1.uppsida() << ", Mynt 2: " << m2.uppsida() << endl;
        if(m1.uppsida() == m2.uppsida())
            counter++;
    }
    cout << "Antalet lika: " << counter << endl;

//c)
    cout << endl << "Uppgift c: " << endl;
    int antalMynt;
    int antalLika = 0;
    antalKast = 0;
    cout << "Mata in antal mynt: ";
    cin >> antalMynt;

    bool allaLika = true;
    Mynt allaMynt[antalMynt];

    cout << "Mata in antal kast: ";
    cin >> antalKast;

    for(int i = 0; i<antalKast;++i){
        allaLika = true;
        for(int j=0;j<antalMynt;++j){
            allaMynt[j].kasta();
            if(allaMynt[0].uppsida() != allaMynt[j].uppsida())
                allaLika = false;
        }
        if(allaLika)
            antalLika++;
    }
    cout << "Antalet lika: " << antalLika << endl;

    return 0;
}
