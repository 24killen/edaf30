#include <iostream>
#include "Vektor.h"

using namespace std;

int main(){
    try{
        Vektor v = Vektor(10);
        v[15] = 5;
    }catch(invalid_argument){
        cout<<"Invalid";
    }
    return 0;
}
