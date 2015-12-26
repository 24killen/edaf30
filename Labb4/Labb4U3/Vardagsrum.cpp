#include "Vardagsrum.h"
using namespace std;
Vardagsrum::Vardagsrum(){

}
Vardagsrum::~Vardagsrum(){
}
void Vardagsrum::skriv(){
    Rum::skriv();
    cout<<", Balkong: ";
    if(balkong)
        cout<<"Ja";
    else
        cout<<"Nej";
    cout<<endl;
}
