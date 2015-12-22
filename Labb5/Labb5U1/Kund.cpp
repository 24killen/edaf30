#include "Kund.h"
Kund::Kund(int a)
{
    Kund::atid = a;
    Kund::btid = rand()%4 + 1;
}

Kund::~Kund()
{

}

int Kund::getATid(){
    return Kund::atid;
}

int Kund::getBTid(){
    return Kund::btid;
}

bool Kund::isDone(int time){
    btid -= time;
    return (btid<=0);
}
