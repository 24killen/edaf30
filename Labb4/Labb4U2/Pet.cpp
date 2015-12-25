#include "Pet.h"

Pet::~Pet(){
    //dtor
}

Pet::Pet(const Pet& other){
    //copy ctor
}

Pet& Pet::operator=(const Pet& rhs){
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
