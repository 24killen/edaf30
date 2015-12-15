#include "Personnummer.h"
#include <iostream>
using namespace std;
Personnummer::Personnummer(){
    pNbrOK = false;
}

Personnummer::~Personnummer(){
    //delete persNbr;
}

bool Personnummer::validate(){
    int pNbr[11];
    int sum = 0;
    for (int i = 0; i < 9; i++){
        if(i%2 == 0){ // udda = jämna eftersom vi börjar på plats 0.
            pNbr[i] = (int)(persNbr[i]-'0')*2;
        }else{
            pNbr[i] = (int)(persNbr[i]-'0');
        }

        if(pNbr[i] >= 10){
            sum += pNbr[i]/10;
        }
        sum += pNbr[i]%10;
        cout << pNbr[i] << " Summan: " << sum << endl;
    }
    int entalssiffran = sum%10;
    cout << "Ental: " << entalssiffran << endl;
    if((int)(persNbr[9]-'0') == (10-entalssiffran) || ((entalssiffran == 0) && (int)(persNbr[9]-'0') == 0)){
        pNbrOK = true;
    }else{
        pNbrOK = false;
    }
    return pNbrOK;
}

bool Personnummer::operator!(){
    validate();
    return !pNbrOK;
}


std::ostream& operator<<(std::ostream& out, const Personnummer& pNbr){
    out << pNbr.persNbr;
    return out;
}

std::istream& operator>>(std::istream& in,Personnummer& pNbr){
    in >> pNbr.persNbr;
    return in;
}
