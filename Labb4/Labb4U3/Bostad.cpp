#include "Bostad.h"
#include "Sovrum.h"
#include "Badrum.h"
#include "Vardagsrum.h"
#include "Kok.h"
#include <vector>

Bostad::Bostad(int a, bool b, bool c, int d, bool e, int f, bool g, vector<int> h, vector<int> i) {
            k = Kok(a, b, c);
            bad = Badrum(d, e);
            var = Vardagsrum(f, g);

            for(int j=0;j<h.size();++j){
                int storlek = h.at(j);
                int antal = i.at(j);
                srum.push_back(Sovrum(storlek, antal));
            }
}

Bostad::~Bostad(){
    srum.clear();
}
void Bostad::skriv(){
    cout<<"Kök: ";
    k.skriv();
    cout<<"Badrum: ";
    bad.skriv();
    cout<<"Vardagsrum: ";
    var.skriv();
    for(int i=0;i<srum.size();++i){
        cout<<"Sovrum: ";
        (srum.at(i)).skriv();
    }
}
