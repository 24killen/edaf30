#include "Badrum.h"
using namespace std;
Badrum::Badrum(){
}
Badrum::~Badrum(){
}
void Badrum::skriv(){
    Rum::skriv();
    cout<<", Dusch: ";
    if(dusch)
        cout<<"Ja";
    else
        cout<<"Nej";
    cout<<endl;
}
