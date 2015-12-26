#include "Kok.h"
using namespace std;
Kok::Kok(){
    //ctor
}
Kok::~Kok(){
    //dtor
}
void Kok::skriv(){
    Rum::skriv();
    cout<<", Diskmaskin: ";
    if(diskmaskin)
        cout<<"Ja";
    else
        cout<<"Nej";

    cout<<", Frys: ";
    if(frys)
        cout<<"Ja";
    else
        cout<<"Nej";
    cout<<endl;
}
