#include "filhantering.h"

Filhantering::Filhantering()
{
    filnamn = "Fil.txt";
    ifstream input;
    ofstream output;
}

Filhantering::~Filhantering()
{
    //dtor
}

void Filhantering::spara(){
    cout << "TEST" << filnamn << endl;
    try{
        output.open(filnamn);
        //output << "Hejsan";
      /*
        for(int i = 0; i < 1; ++i){
            output << "test" ;//<< vec.at(i).getKontoinnehavare() << " - " << vec.at(i).getKontonummer() << " - " << vec.at(i).getKontotyp() << " - " << vec.at(i).getSaldo() << endl;
        }
        */
        cout << "TEST2";
        output.close();
    }catch(exception &e){
        cout << "BANANA";
    }

}

void Filhantering::ladda(vector<Konto> &vec){
    input.open(filnamn);

    input.close();
}
