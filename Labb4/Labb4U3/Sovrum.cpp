#include "Sovrum.h"
Sovrum::Sovrum(){
}
Sovrum::~Sovrum(){
}
void Sovrum::skriv(){
    Rum::skriv();
    std::cout<<", "<<garderober<<" garderober"<<std::endl;
}
