#include <iostream>
#include <vector>
#include "Bostad.h"

using namespace std;

int main(){
    vector<int> sovrumsstorlek{16,14};
    vector<int> garderober{4,3};
    Bostad minLya(12,false,true,    //Kök
                   4,true,          //Badrum
                   24,false,        //vardagsrum
                   sovrumsstorlek,
                   garderober);
    minLya.skriv();
    return 0;
}
